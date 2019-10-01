#pragma once

namespace USING
{
	using _DataType = char;
	using _KeyType = unsigned short;
	using _MemoryPoolIndex = const unsigned int;
}using namespace USING;

namespace NETWORK
{
	constexpr unsigned short MAIN_SERVER_PORT = 9000;

	constexpr unsigned int RECV_BUFFER_MAX_SIZE = 128; //std::numeric_limits<unsigned char>::max();
}

namespace PACKET
{
	namespace PACKET_TYPE
	{

	}

	namespace PACKET_DATA
	{

	}

}using namespace PACKET;

namespace ATOMIC_UTIL
{
	template <class TYPE> 
	inline bool T_CAS(std::atomic<TYPE>* addr, TYPE oldValue, TYPE newValue) noexcept
	{
		return atomic_compare_exchange_strong(addr, &oldValue, newValue);
	};

	template <class TYPE> 
	inline bool T_CAS(volatile TYPE* addr, TYPE oldValue, TYPE newValue) noexcept
	{
		return atomic_compare_exchange_strong(reinterpret_cast<volatile std::atomic<TYPE>*>(addr), &oldValue, newValue);
	};
}