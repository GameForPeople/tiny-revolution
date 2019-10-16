#include "stdafx.h"

#include "Server.h"

#include "LogManager.h"
#include "ConnectManager.h"

namespace WonSY 
{
	Server::Server()
		: io_service() // io_Service의 생성이 선행되어야 합니다.
		, acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), DEFINE::MAIN_SERVER_PORT))
		, acceptSocket(io_service)
	{
		AcceptClient();
	}

	Server::~Server()
	{
		for (auto& thread : workerThreadCont) { thread.join(); }
	}

	void Server::AcceptClient()
	{
		acceptor.async_accept(acceptSocket,
			[this](boost::system::error_code ec)
			{
				if (!ec)
				{
					if (auto [isEnter, key] = ConnectManager::GetInstance().EnterServer()
						; isEnter)
					{
						// Connect

					}
					else
					{
						// DisConnect
					}
					// std::make_shared<session>(std::move(socket_))->start();
				}
				AcceptClient();
			}
		);
	}

	void Server::StartWorkerThread()
	{
		LogManager::GetInstance().AddLog(WonSY::LOG_TYPE::DEV_LOG, L" Worker Thread를 " + DEFINE::WORKER_THREAD_COUNT + std::wstring(L"개 생성합니다."), WonSY::SourceLocation(SOURCE_LOCATION));

		for (int index = 0, threadCount = DEFINE::WORKER_THREAD_COUNT; index < threadCount; ++index)
		{
			workerThreadCont.emplace_back(
				[this, index]()
				{
					io_service.run();
				}
			);
			
			//workerThreadCont.emplace_back(
			//	[this, index]()
			//	{
			//		WorkerThreadFunction(index);
			//	}
			//);
		}
	}
}