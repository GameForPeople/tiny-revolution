#include "stdafx.h"

#include "TimerUnit.h"
#include "TimerManager.h"

#include "LogManager.h"
#include "ConnectManager.h"

namespace WonSY
{
	TimerManager TimerManager::instance(SINGLETON_INSTANCE::DEFAULT);

	TimerManager::TimerManager(SINGLETON_INSTANCE)
		: timerThread()
		, timerCont()
		, timerMemoryPool()
	{
		if (ATOMIC_UTIL::T_CAS(&instanceFlag, false, true) == false)
		{
			std::cout << "ERROR TimerManager�� �����ڰ� �ι� ȣ��Ǿ����ϴ�." << std::endl;
			throw ERROR;
		}

		for (int i = 0; i < DEFINE::MAX_TIMER_COUNT; ++i) { timerMemoryPool.push(new TimerUnit()); }

		timerThread = std::thread([this]() {this->TimerThread(THREAD_INSTANCE::DEFAULT); });
	}

	TimerManager::~TimerManager()
	{
		TimerUnit* retTimerUnit = nullptr;
		while (timerMemoryPool.try_pop(retTimerUnit)) { delete retTimerUnit; }
		while (timerCont.try_pop(retTimerUnit)) { delete retTimerUnit; }
	}

	void TimerManager::AddTimerEvent(const TIMER_TYPE inTimerType, const _KeyType ownerKey, const _KeyType targetKey, const TIME waitTime)
	{
		TimerUnit* timerUnit = PopTimerUnit();

		timerUnit->timerType = inTimerType;
		timerUnit->ownerKey = ownerKey;
		timerUnit->targetKey = targetKey;
		timerUnit->eventTime = GetTickCount64() + static_cast<_TimeType>(waitTime);
		
		timerCont.push(timerUnit);
	}

	void TimerManager::AddTimerEvent(TimerUnit* timerUnit, const TIME waitTime)
	{
		timerUnit->eventTime = GetTickCount64() + static_cast<_TimeType>(waitTime);
		timerCont.push(timerUnit);
	}

	void TimerManager::TimerThread(THREAD_INSTANCE)
	{
		while (7)
		{
			std::this_thread::sleep_for(0ns);
			const _TimeType tempNowTime = GetTickCount64();

			while (timerCont.size())
			{
				TimerUnit* retTimerUnit{ nullptr };

				// Timer Cont�� ��ϵ� Ÿ�̸Ӱ� ������ ���� �� ����, ���Ŀ��� �ּ� Ÿ�̸ӷ� Loop!
				while (!timerCont.try_pop(retTimerUnit)) { std::this_thread::sleep_for(100ms); }

				if (tempNowTime < retTimerUnit->eventTime)
				{
					// ����
					timerCont.push(retTimerUnit);
					break;
				}

				if (ProcessTimerUnit(retTimerUnit)) { PushTimerUnit(retTimerUnit); }
			}
		}
	}

	bool TimerManager::ProcessTimerUnit(TimerUnit* retTimerUnit)
	{
		switch (retTimerUnit->timerType)
		{
		case TIMER_TYPE::PUSH_OLD_KEY:
			ConnectManager::GetInstance().PushOldKey(retTimerUnit->ownerKey);
			return true; break;
		default:
			LogManager::GetInstance().AddLog(LOG_TYPE::WARNING_LOG, L"TimerUnit�� ó�������ʴ� Ÿ���� �����մϴ�.", SourceLocation(SOURCE_LOCATION));
			return true; break;
		}
	}

	TimerUnit* TimerManager::PopTimerUnit()
	{
		TimerUnit* retTimerUnit = nullptr;

		return timerMemoryPool.try_pop(retTimerUnit)
			? retTimerUnit
			: []()->TimerUnit* 
		{ 
			LogManager::GetInstance().AddLog(LOG_TYPE::WARNING_LOG, L"Timer�� �����Ͽ� �߰� �Ҵ��Ͽ����ϴ�.", SourceLocation(SOURCE_LOCATION));
			return new TimerUnit(); 
		}();
	}

	void TimerManager::PushTimerUnit(TimerUnit* inTimerUnit)
	{
		timerMemoryPool.push(inTimerUnit);
	}
}