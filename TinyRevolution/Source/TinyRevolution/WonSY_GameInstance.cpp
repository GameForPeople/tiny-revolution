// Fill out your copyright notice in the Description page of Project Settings.

#include "WonSY_GameInstance.h"

// #include "Sockets.h"
// #include "IPAddress.h"

void UWonSY_GameInstance::StartNetwork(bool isUsePublicIP)
{
	socket = FTcpSocketBuilder("ClientSocket")
		.AsReusable()
		.AsNonBlocking()
		.WithReceiveBufferSize(1000)
		.WithSendBufferSize(1000);

	FString ipString = [&, isUsePublicIP]() noexcept
	{ 
		return isUsePublicIP ? PUBLIC_SERVER_IP : LOCAL_HOST_IP;
	}();

	TArray<uint8> ipCont;
	{
		TArray<FString> Tokens;
		if (ipString.ParseIntoArray(Tokens, TEXT("."), false) == 4)
		{
			for (int i = 0; i < 4; ++i) 
			{ 
				//ipCont[i] = FCString::Atoi(*Tokens[i]); 
				ipCont.Add(FCString::Atoi(*Tokens[i]));
			}
		}
		else
		{
			UE_LOG(LogTemp, Fatal, TEXT("IP 제작에 실패했습니다."));
		}
	}
	
	TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetPort(9000);
	addr->SetRawIp(ipCont);
	
	if (socket->Connect(*addr))
	{
		UE_LOG(LogTemp, Display, TEXT("커넥트에 성공했습니다."));
	}
	else
	{
		UE_LOG(LogTemp, Fatal, TEXT("커넥트에 실패했습니다."));
	}

	networkThread = std::thread([&]() { this->NetworkFunction(); });
	networkThread.detach();
}

void UWonSY_GameInstance::EndNetwork()
{
	isNetworkEnd = false;

	std::this_thread::sleep_for(std::chrono::seconds(2));

	if (socket)
	{
		socket->Close();
		delete socket;
	}
}

void UWonSY_GameInstance::NetworkFunction()
{
	while (isNetworkEnd)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));	// 1초에 10번 네트워크 할 것.

		TArray<uint8> sendedBuffer;

		// Send!
		while (sendTaskQueue.Dequeue(sendedBuffer))
		{
			int32 sendpacketSize{ sendedBuffer[0] };
			int32 sendSuccessByteCount{ 0 };

			while (sendpacketSize != sendSuccessByteCount)
			{
				socket->Send(sendedBuffer.GetData() + sendSuccessByteCount
					, sendedBuffer[0] - sendSuccessByteCount
					, sendSuccessByteCount);
			}
		}

		// Recv!
		uint32 recvSize;

		if (socket->HasPendingData(recvSize))
		{
			int32 recvSuccessByteCount;

			socket->Recv(recvBuffer, 512, recvSuccessByteCount, ESocketReceiveFlags::Type::None);
			
			uint8 packetSize;
			uint8* pBuf = recvBuffer;

			if (0 < loadedSize) packetSize = loadedBuffer[0];

			// 처리하지 않은 버퍼의 크기가 있으면, 계속 루프문을 돕니다.
			while (recvSuccessByteCount > 0)
			{
				// 이전에 처리를 마치지 못한 버퍼를 처리해야한다면 패스, 아니라면 지금 처리해야할 패킷의 크기를 받음.
				if (packetSize == 0) packetSize = static_cast<uint8>(pBuf[0]);

				// 처리해야하는 패킷 사이즈 중에서, 이전에 이미 처리한 패킷 사이즈를 빼준다.
				int required = packetSize - loadedSize;

				// 패킷을 완성할 수 있을 때 (요청해야할 사이즈보다, 남은 사이즈가 크거나 같을 때)
				if (recvSuccessByteCount >= required)
				{
					memcpy(loadedBuffer + loadedSize, pBuf, required);

					//-------------------------------------------------------------------------------
					ProcessPacket();  // 패킷처리
					//-------------------------------------------------------------------------------

					loadedSize = 0;
					packetSize = 0;
					recvSuccessByteCount -= required;
					pBuf += required;
				}
				// 패킷을 완성할 수 없을 때
				else
				{
					memcpy(loadedBuffer + loadedSize, pBuf, recvSuccessByteCount);
					loadedSize += recvSuccessByteCount;
					break;
				}
			}
		}
	}
}

void UWonSY_GameInstance::ProcessPacket()
{
	switch(loadedBuffer[1])
	{
	case 1:
	{

	}
	break;
	default:
		break;
	}
}
