#pragma once

namespace DEFINE
{
	const int WORKER_THREAD_COUNT = std::thread::hardware_concurrency();
}

namespace WonSY
{
	class Server
	{
	public:
		Server();
		~Server();

	private:
		void AcceptClient();
		void StartWorkerThread();

	private:
		boost::asio::io_service io_service;
		boost::asio::ip::tcp::acceptor acceptor;
		boost::asio::ip::tcp::socket acceptSocket;

		std::vector<std::thread> workerThreadCont;
	};
}