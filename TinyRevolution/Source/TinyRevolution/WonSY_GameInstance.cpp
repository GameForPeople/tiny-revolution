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
			UE_LOG(LogTemp, Fatal, TEXT("IP ���ۿ� �����߽��ϴ�."));
		}
	}
	
	TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetPort(9000);
	addr->SetRawIp(ipCont);
	
	if (socket->Connect(*addr))
	{
		UE_LOG(LogTemp, Display, TEXT("Ŀ��Ʈ�� �����߽��ϴ�."));
	}
	else
	{
		UE_LOG(LogTemp, Fatal, TEXT("Ŀ��Ʈ�� �����߽��ϴ�."));
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
		std::this_thread::sleep_for(std::chrono::milliseconds(100));	// 1�ʿ� 10�� ��Ʈ��ũ �� ��.

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

			// ó������ ���� ������ ũ�Ⱑ ������, ��� �������� ���ϴ�.
			while (recvSuccessByteCount > 0)
			{
				// ������ ó���� ��ġ�� ���� ���۸� ó���ؾ��Ѵٸ� �н�, �ƴ϶�� ���� ó���ؾ��� ��Ŷ�� ũ�⸦ ����.
				if (packetSize == 0) packetSize = static_cast<uint8>(pBuf[0]);

				// ó���ؾ��ϴ� ��Ŷ ������ �߿���, ������ �̹� ó���� ��Ŷ ����� ���ش�.
				int required = packetSize - loadedSize;

				// ��Ŷ�� �ϼ��� �� ���� �� (��û�ؾ��� �������, ���� ����� ũ�ų� ���� ��)
				if (recvSuccessByteCount >= required)
				{
					memcpy(loadedBuffer + loadedSize, pBuf, required);

					//-------------------------------------------------------------------------------
					ProcessPacket();  // ��Ŷó��
					//-------------------------------------------------------------------------------

					loadedSize = 0;
					packetSize = 0;
					recvSuccessByteCount -= required;
					pBuf += required;
				}
				// ��Ŷ�� �ϼ��� �� ���� ��
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
