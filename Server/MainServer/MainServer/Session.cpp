#include "stdafx.h"
#include "MappedMemoryUnit.h"

#include "Session.h"

#include "SendManager.h"

namespace WonSY
{
	Session::Session(boost::asio::io_context& io_service) noexcept
		: socket(io_service)
		, receiveBuffer()
		, memoryPoolIndex()
	{
	}

	boost::asio::ip::tcp::socket& Session::GetSocket()
	{
		return socket;
	}

	_MemoryPoolIndex Session::GetMemoryPoolIndex()
	{
		return memoryPoolIndex;
	}

	void Session::PostReceive()
	{
		memset(&receiveBuffer, '\0', sizeof(receiveBuffer));

		socket.async_read_some(boost::asio::buffer(receiveBuffer)
			, boost::bind(&Session::ProcessReceive
				, this
				, boost::asio::placeholders::error
				, boost::asio::placeholders::bytes_transferred
			)
		);
	}

	void Session::ProcessWrite(const boost::system::error_code& /*error*/, size_t /*bytes_transferred*/, MappedMemoryUnit* sendMemoryUnit)
	{
		SendManager::GetInstance().PushMemory(sendMemoryUnit);
	}

	void Session::ProcessReceive(const boost::system::error_code& error, size_t bytes_transferred)
	{
		if (error)
		{
			if (error == boost::asio::error::eof)
			{
				std::cout << "클라이언트와 연결이 끊어졌습니다" << std::endl;
			}
			else
			{
				std::cout << "error No: " << error.value() << " error Message: " << error.message() << std::endl;
			}
		}
		else
		{
			const std::string strRecvMessage = receiveBuffer.data();
			std::cout << "클라이언트에서 받은 메시지: " << strRecvMessage << ", 받은 크기: " << bytes_transferred << std::endl;

			char szMessage[128] = { 0, };
			sprintf_s(szMessage, 128 - 1, "Re:%s", strRecvMessage.c_str());
			//writeMessage = szMessage;
			//
			//boost::asio::async_write( socket
			//	, boost::asio::buffer(writeMessage)
			//	, boost::bind( &Session::ProcessWrite
			//		, this
			//		, boost::asio::placeholders::error
			//		, boost::asio::placeholders::bytes_transferred
			//	)
			//);

			PostReceive();
		}
	}
}