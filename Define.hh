#pragma once

#ifdef FOR_SERVER
#define UENUM(x) /* void */
#define UMETA(x) /* void */
#else
#define FOR_CLIENT
#endif


namespace USING
{
#ifdef FOR_SERVER
	using _String = char[];
	using _Short = unsigned short;
	using _Enum = unsigned char;

	using _DataType = char;
	using _KeyType = unsigned int;
	using _clientKeyType = unsigned short;
	using _MemoryPoolIndex = const unsigned int;
	using _TimeType = unsigned long long;
#else
	using _String = FString;
	using _Short = uint16;
	using _Enum = uint8;

	using _DataType = uint8;
	using _KeyType = uint32;
	using _clientKeyType = uint16;

	using _MemoryPoolIndex = const unsigned int;
	using _TimeType = uint64;
#endif
}using namespace USING;

namespace DEFINE
{
	const _String LOCAL_HOST_IP = "127.0.0.1";
	const _String PUBLIC_SERVER_IP = "13.125.73.63";

	constexpr _Short MAIN_SERVER_PORT = 9000;

	constexpr _Short PACKET_MAX_SIZE = 256;
	constexpr _Short RECV_BUFFER_MAX_SIZE = 1025; //std::numeric_limits<unsigned char>::max();
}

UENUM(BlueprintType)
enum class NETWORK_TYPE : _Enum
{
	// CLIENT 0
	CLIENT_RECV_FROM_MAIN UMETA(DisplayName = "CLIENT_RECV_FROM_MAIN"),
	CLIENT_RECV_FROM_CHAT UMETA(DisplayName = "CLIENT_RECV_FROM_CHAT"),
	CLIENT_RECV_FROM_WAIT UMETA(DisplayName = "CLIENT_RECV_FROM_WAIT"),

	CLIENT_SEND_TO_MAIN UMETA(DisplayName = "CLIENT_SEND_TO_MAIN"),
	CLIENT_SEND_TO_CHAT UMETA(DisplayName = "CLIENT_SEND_TO_CHAT"),
	CLIENT_SEND_TO_WAIT UMETA(DisplayName = "CLIENT_SEND_TO_WAIT"),

	// MAIN 1
	MAIN_RECV_FROM_CLIENT UMETA(DisplayName = "MAIN_RECV_FROM_CLIENT"),
	MAIN_RECV_FROM_QUERY UMETA(DisplayName = "MAIN_RECV_FROM_QUERY"),
	MAIN_RECV_FROM_WAIT UMETA(DisplayName = "MAIN_RECV_FROM_WAIT"),
	MAIN_RECV_FROM_COMMAND UMETA(DisplayName = "MAIN_RECV_FROM_COMMAND"),

	MAIN_SEND_TO_CLIENT UMETA(DisplayName = "MAIN_SEND_TO_CLIENT"),
	MAIN_SEND_TO_QUERY UMETA(DisplayName = "MAIN_SEND_TO_QUERY"),
	MAIN_SEND_TO_WAIT UMETA(DisplayName = "MAIN_SEND_TO_WAIT"),
	MAIN_SEND_TO_COMMAND UMETA(DisplayName = "MAIN_SEND_TO_COMMAND"),

	// CHAT 2
	CHAT_RECV_FROM_CLIENT UMETA(DisplayName = "CHAT_RECV_FROM_CLIENT"),
	CHAT_RECV_FROM_MAIN UMETA(DisplayName = "CHAT_RECV_FROM_MAIN"),
	CHAT_RECV_FROM_COMMAND UMETA(DisplayName = "CHAT_RECV_FROM_COMMAND"),

	CHAT_SEND_TO_CLIENT UMETA(DisplayName = "CHAT_SEND_TO_CLIENT"),
	CHAT_SEND_TO_MAIN UMETA(DisplayName = "CHAT_SEND_TO_MAIN"),
	CHAT_SEND_TO_COMMAND UMETA(DisplayName = "CHAT_SEND_TO_COMMAND"),

	// WAIT 3
	WAIT_RECV_FROM_CLIENT UMETA(DisplayName = "WAIT_RECV_FROM_CLIENT"),
	WAIT_RECV_FROM_MAIN UMETA(DisplayName = "WAIT_RECV_FROM_MAIN"),
	WAIT_RECV_FROM_COMMAND UMETA(DisplayName = "WAIT_RECV_FROM_COMMAND"),

	WAIT_SEND_TO_CLIENT UMETA(DisplayName = "WAIT_SEND_TO_CLIENT"),
	WAIT_SEND_TO_MAIN UMETA(DisplayName = "WAIT_SEND_TO_MAIN"),
	WAIT_SEND_TO_COMMAND UMETA(DisplayName = "WAIT_SEND_TO_COMMAND"),

	// QUERY 4
	QUERY_RECV_FROM_MAIN UMETA(DisplayName = "QUERY_RECV_FROM_MAIN"),
	QUERY_RECV_FROM_CHAT UMETA(DisplayName = "QUERY_RECV_FROM_CHAT"),

	QUERY_SEND_TO_MAIN UMETA(DisplayName = "QUERY_SEND_TO_MAIN"),
	QUERY_SEND_TO_CHAT UMETA(DisplayName = "QUERY_SEND_TO_CHAT"),

	// COMMAND 5
	COMMAND_RECV_FROM_CHAT UMETA(DisplayName = "COMMAND_RECV_FROM_CHAT"),
	COMMAND_RECV_FROM_MAIN UMETA(DisplayName = "COMMAND_RECV_FROM_MAIN"),

	COMMAND_SEND_TO_CHAT UMETA(DisplayName = "COMMAND_SEND_TO_CHAT"),
	COMMAND_SEND_TO_MAIN UMETA(DisplayName = "COMMAND_SEND_TO_MAIN"),

	ENUM_SIZE UMETA(DisplayName = "ENUM_SIZE")
};

namespace PACKET
{
	namespace PACKET_TYPE
	{
		UENUM(BlueprintType)
		enum class CLIENT_TO_MAIN : _Enum
		{
			MOVE UMETA(DisplayName = "CTM_MOVE"),
			
			LOGIN UMETA(DisplayName = "CTM_LOGIN"),
			SIGN_UP UMETA(DisplayName = "CTM_SIGN_UP"),
			
			ATTACK UMETA(DisplayName = "CTM_ATTACK"),
			SKILL UMETA(DisplayName = "CTM_SKILL"),
			
			USE_ITEM UMETA(DisplayName = "CTM_USE_ITEM"),
			BUY_ITEM UMETA(DisplayName = "CTM_BUY_ITEM"),
			ENUM_SIZE UMETA(DisplayName = "CTM_ENUM_SIZE")
		};

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

		enum class MAIN_TO_CLIENT
		{
			MOVE,

			LOGIN_OK,
			LOGIN_FAIL,

			PUT_PLAYER,
			REMOVE_PLAYER,

			STAT_CHANGE,
			ENUM_SIZE
		};

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

#ifdef FOR_SERVER
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

namespace TIME_UTIL
{
	inline const std::string GetCurrentDateTime()
	{
		time_t     now = time(0); //현재 시간을 time_t 타입으로 저장
		struct tm  tstruct;
		char       buf[80];
		localtime_s(&tstruct, &now);
		strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct); // YYYY-MM-DD.HH:mm:ss 형태의 스트링

		return buf;
	}
}

namespace UNICODE_UTIL
{
	void SetLocaleForKorean()
	{
		_wsetlocale(LC_ALL, L"Korean");
		auto oldLocale = std::wcout.imbue(std::locale("korean"));
	}

#ifdef _WINDOWS_
	_NODISCARD inline std::string WStringToString(const std::wstring& InWideString)
	{
		const int sizeBuffer = WideCharToMultiByte(CP_ACP, 0, &InWideString[0], -1, NULL, 0, NULL, NULL);
		std::string retString(sizeBuffer, 0);
		WideCharToMultiByte(CP_ACP, 0, &InWideString[0], -1, &retString[0], sizeBuffer, NULL, NULL);

		// FixError ==
		retString.pop_back(); //(retString.end(), retString.end());
		//retString.insert(retString.end(), '\0');

		return retString;
	}

	_NODISCARD inline std::wstring StringToWString(const std::string& InString)
	{
		const int sizeBuffer = MultiByteToWideChar(CP_ACP, 0, &InString[0], -1, NULL, 0);
		std::wstring retString(sizeBuffer, 0);
		MultiByteToWideChar(CP_ACP, 0, &InString[0], -1, &retString[0], sizeBuffer);
		return retString;
	}
#else
	_NODISCARD inline std::string WStringToString(const std::wstring& InWideString)
	{
		char chr[100];
		wcstombs(chr, InWideString.c_str(), InWideString.size());

		return chr;
	}

	_NODISCARD inline std::wstring StringToWString(const std::string& InString)
	{
		wchar_t wcsarr[100];
		mbstowcs(wcsarr, InString.c_str(), InString.size());

		return wcsarr;
	}
#endif
}

namespace ERROR_UTIL
{
	//_NORETURN inline void ERROR_QUIT(const WCHAR* msg)
	//{
	//	LPVOID lpMsgBuf;
	//	FormatMessage(
	//		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
	//		NULL,
	//		WSAGetLastError(),
	//		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
	//		(LPTSTR)&lpMsgBuf,
	//		0,
	//		NULL
	//	);

	//	// LogManager::GetInstance()->AddLog(LOG_TYPE::ERROR_LOG, (LPTSTR)lpMsgBuf);
	//	MessageBox(NULL, (LPTSTR)lpMsgBuf, msg, MB_ICONERROR);
	//	LocalFree(lpMsgBuf);
	//	exit(1);
	//};
	//

	//inline void ERROR_DISPLAY(const WCHAR* msg)
	//{
	//	LPVOID lpMsgBuf;
	//	FormatMessage(
	//		FORMAT_MESSAGE_ALLOCATE_BUFFER |
	//		FORMAT_MESSAGE_FROM_SYSTEM,
	//		NULL, WSAGetLastError(),
	//		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
	//		(LPTSTR)&lpMsgBuf, 0, NULL);

	//	LogManager::GetInstance()->AddLog(LOG_TYPE::WARNING_LOG, (WCHAR*)lpMsgBuf);
	//	wprintf(L"[%s] %s", msg, (WCHAR*)lpMsgBuf);
	//	LocalFree(lpMsgBuf);
	//}
}
#endif