#pragma once

namespace DEFINE
{
}

struct TimerUnit;

namespace WonSY
{
	/*
		!0. �⺻ �̱���.. ���� ��ü ����ϸ� ������ ��ȣ��Ǿ����.
	*/
	class TimerManager /* Singleton */
	{
		enum class SINGLETON_INSTANCE { DEFAULT = 0 };
		enum class THREAD_INSTANCE { DEFAULT = 0 };

	public:
		TimerManager() = delete;
		TimerManager(SINGLETON_INSTANCE);
		TimerManager(const TimerManager& other) = delete;
		TimerManager& operator=(const TimerManager&) = delete;

		~TimerManager();

		inline static TimerManager& GetInstance() noexcept { return TimerManager::instance; }

	public:
		void AddTimerEvent(const TIMER_TYPE, const _KeyType ownerKey, const _KeyType targetKey, const TIME waitTime);
		void AddTimerEvent(TimerUnit*, const TIME waitTime);

		void TimerThread(THREAD_INSTANCE);
	private:

		bool ProcessTimerUnit(TimerUnit*);	// return true - ��ȯ �ʿ�, false - ������

		_NODISCARD TimerUnit* PopTimerUnit();
		void PushTimerUnit(TimerUnit*);

	private:
		/*inline*/ static TimerManager instance;
		inline static std::atomic<bool> instanceFlag{ false };

		std::thread timerThread;

		concurrency::concurrent_priority_queue<TimerUnit*, TimerUnitCompareFunction> timerCont;
		concurrency::concurrent_queue<TimerUnit*> timerMemoryPool;
	};
}