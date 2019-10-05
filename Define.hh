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

namespace NETWORK_TYPE
{
	enum /*class NETWORK_TYPE : BYTE */
	{
		// CLIENT 0
		CLIENT_RECV_FROM_MAIN,/* = 0*/
		CLIENT_RECV_FROM_CHAT,
		CLIENT_RECV_FROM_WAIT,

		CLIENT_SEND_TO_MAIN,
		CLIENT_SEND_TO_CHAT,
		CLIENT_SEND_TO_WAIT,

		// MAIN 1
		MAIN_RECV_FROM_CLIENT,
		MAIN_RECV_FROM_QUERY,
		MAIN_RECV_FROM_WAIT,
		MAIN_RECV_FROM_COMMAND,

		MAIN_SEND_TO_CLIENT,
		MAIN_SEND_TO_QUERY,
		MAIN_SEND_TO_WAIT,
		MAIN_SEND_TO_COMMAND,

		// CHAT 2
		CHAT_RECV_FROM_CLIENT,
		CHAT_RECV_FROM_MAIN,
		CHAT_RECV_FROM_COMMAND,
		
		CHAT_SEND_TO_CLIENT,
		CHAT_SEND_TO_MAIN,
		CHAT_SEND_TO_COMMAND,

		// WAIT 3
		WAIT_RECV_FROM_CLIENT,
		WAIT_RECV_FROM_MAIN,
		WAIT_RECV_FROM_COMMAND,

		WAIT_SEND_TO_CLIENT,
		WAIT_SEND_TO_MAIN,
		WAIT_SEND_TO_COMMAND,

		// QUERY 4
		QUERY_RECV_FROM_MAIN,
		QUERY_RECV_FROM_CHAT,

		QUERY_SEND_TO_MAIN,
		QUERY_SEND_TO_CHAT,


		// COMMAND 5
		COMMAND_RECV_FROM_CHAT,
		COMMAND_RECV_FROM_MAIN,

		COMMAND_SEND_TO_CHAT,
		COMMAND_SEND_TO_MAIN,

		ENUM_SIZE
	};
}

namespace PACKET
{
	namespace PACKET_TYPE
	{
		namespace CLIENT_TO_MAIN
		{
			enum
			{
				MOVE,

				LOGIN,
				SIGN_UP,

				ATTACK,
				SKILL,
				USE_ITEM,
				BUY_ITEM,
				ENUM_SIZE
			};
		}

		namespace CLIENT_TO_CHAT
		{
			enum
			{
				CHAT,
				REGISTER_KEY
			};
		}

		namespace CLIENT_TO_WAIT
		{
			enum
			{
				CHECK_CODE,
				DEMAND_CODE
			};
		}

		namespace MAIN_TO_CLIENT
		{
			enum
			{
				MOVE,

				LOGIN_OK,
				LOGIN_FAIL,

				PUT_PLAYER,
				REMOVE_PLAYER,

				STAT_CHANGE,
				ENUM_SIZE
			};
		}

		namespace MAIN_TO_QUERY
		{
			enum
			{
				DEMAND_LOGIN,
				DEMAND_SIGNUP,
				SAVE_LOCATION,
				SAVE_USERINFO
			};
		}

		namespace QUERY_TO_MAIN
		{
			enum
			{
				LOGIN_TRUE,
				LOGIN_FALSE,
				LOGIN_ALREADY,
				LOGIN_NEW
			};
		}

		namespace CHAT_TO_CLIENT
		{
			enum
			{
				CHAT,	// CS::CHAT와 SC::CHAT는 동일해야합니다.
				URGENT_NOTICE,		// ChatServer에서 Client로 긴급 공지를 보낼때.
				ENUM_SIZE
			};
		}

		namespace COMMAND_TO_CHAT
		{
			enum
			{
				URGENT_NOTICE,	// CommandServer에서 ChatServer로 긴급공지 요청을 보냄.
				ENUM_SIZE
			};
		}
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