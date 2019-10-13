#include "stdafx.h"

#include "ConnectManager.h"

namespace WonSY
{
	ConnectManager ConnectManager::instance(SINGLETON_INSTANCE::DEFAULT);

	ConnectManager::ConnectManager(SINGLETON_INSTANCE)
		: connectMemoryPool()
	{
		if (ATOMIC_UTIL::T_CAS(&instanceFlag, false, true) == false)
		{
			std::cout << "ERROR ConnectManager의 생성자가 두번 호출되었습니다." << std::endl;
			throw ERROR;
		}

		for (int inKey = 0; inKey < DEFINE::MAX_USER; ++inKey) { connectMemoryPool.push(inKey); }
	}

	std::pair<bool, _KeyType> ConnectManager::EnterServer()
	{
		_KeyType key{ -1 }; 
		return connectMemoryPool.try_pop(key)
			? std::make_pair(true, key)
			: std::make_pair(false, key);
	}

	void ConnectManager::PushOldKey(const _KeyType key)
	{
		connectMemoryPool.push(key);
	}
}