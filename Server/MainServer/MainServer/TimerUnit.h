#pragma once

namespace DEFINE
{
	constexpr unsigned int MAX_TIMER_COUNT = 1000000;
}

namespace WonSY
{
	enum class TIME : /*unsigned short*/ _TimeType
	{
		SECOND = 1000,
		MINUTE = 60000
	};

	enum class TIMER_TYPE 
	{
		PUSH_OLD_KEY
	};

	struct TimerUnit
	{
		TIMER_TYPE timerType;
		_KeyType ownerKey;	// 해당 타이머를 제작한 키.
		_KeyType targetKey; // 해당 타이머의 목적이 되는 키.
		_TimeType eventTime;
		// std::any timerData;	// timerType에 따른 Data를 가짐.
	
	public:
		TimerUnit() = default;
		~TimerUnit() = default;
	};

	struct TimerUnitCompareFunction
	{
		bool operator()(TimerUnit* left, TimerUnit* right) noexcept
		{
			return (left->eventTime) > (right->eventTime);
		}
	};
}