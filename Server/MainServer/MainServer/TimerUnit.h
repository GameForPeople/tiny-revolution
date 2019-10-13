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
		_KeyType ownerKey;	// �ش� Ÿ�̸Ӹ� ������ Ű.
		_KeyType targetKey; // �ش� Ÿ�̸��� ������ �Ǵ� Ű.
		_TimeType eventTime;
		// std::any timerData;	// timerType�� ���� Data�� ����.
	
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