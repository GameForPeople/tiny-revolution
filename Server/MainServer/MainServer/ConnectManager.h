#pragma once

namespace DEFINE
{
	constexpr _KeyType MAX_USER = 10000;
}

namespace WonSY
{
	/*
		!0. 기본 싱글턴.. 정적 객체 사용하며 생성자 비호출되어야함.
	*/
	class ConnectManager /* Singleton */
	{
		enum class SINGLETON_INSTANCE { DEFAULT = 0 };

	public:
		ConnectManager() = delete;
		ConnectManager(SINGLETON_INSTANCE);
		ConnectManager(const ConnectManager& other) = delete;
		ConnectManager& operator=(const ConnectManager&) = delete;

		inline static ConnectManager& GetInstance() noexcept { return ConnectManager::instance; }

	public:
		std::pair<bool, _KeyType> EnterServer();
		void PushOldKey(const _KeyType);

	private:
		/*inline*/ static ConnectManager instance;
		inline static std::atomic<bool> instanceFlag{ false };

		concurrency::concurrent_queue<_KeyType> connectMemoryPool;
	};
}