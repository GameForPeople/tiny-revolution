#pragma once

struct MappedMemoryUnit;

namespace WonSY 
{
	class Session
	{
	public:
		Session(boost::asio::io_context& io_service) noexcept;
		void PostReceive();

		boost::asio::ip::tcp::socket& GetSocket();
		_MemoryPoolIndex GetMemoryPoolIndex();

		void ProcessWrite(const boost::system::error_code& /*error*/, size_t /*bytes_transferred*/, MappedMemoryUnit*);

	private:
		void ProcessReceive(const boost::system::error_code& error, size_t bytes_transferred);

		boost::asio::ip::tcp::socket socket;
		std::array<_DataType, DEFINE::RECV_BUFFER_MAX_SIZE> receiveBuffer;

		_MemoryPoolIndex memoryPoolIndex;
		//std::string writeMessage;
	};
}