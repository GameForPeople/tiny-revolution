#include "stdafx.h"

#include "MappedMemoryUnit.h"
#include "MappedMemoryPool.h"
#include "Session.h"

#include "SendManager.h"

SendManager SendManager::instance(SINGLETON_INSTANCE::DEFAULT);

SendManager::SendManager(SINGLETON_INSTANCE)
	: sendMemoryPool(make_unique<MappedMemoryPool<MappedMemoryUnit>>(
		MappedMemoryPool<MappedMemoryUnit>::CONSTRUCTOR_POSITION::SEND_MEMORY_MANAGER,
		MappedMemoryPool<MappedMemoryUnit>::MEMORY_POOL_MAPPED_SIZE::SEND_MEMORY_POOL,
		MappedMemoryPool<MappedMemoryUnit>::MEMORY_UNIT_COUNT::SEND_MEMORY_POOL
		)
	)
{
	if (ATOMIC_UTIL::T_CAS(&onceFlag, false, true) == false)
	{
		std::cout << "ERROR SendManager의 생성자가 두번 호출되었습니다." << std::endl;
		throw ERROR;
	}
}

SendManager& SendManager::GetInstance() noexcept
{
	return instance;
}

void SendManager::SendData(_DataType* data, Session* session) noexcept
{
	const _DataType sendDataSize = data[0];
	auto sendMemoryUnit = PopMemoryUnit(session->GetMemoryPoolIndex());
	
	memcpy(&(sendMemoryUnit->buffer), data, sendDataSize);

    //boost::asio::async_write( socket
    //	, boost::asio::buffer(sendMemoryUnit->buffer, sendDataSize)
    //	, boost::bind( &Session::ProcessWrite
    //		, session
    //		, boost::asio::placeholders::error
    //		, boost::asio::placeholders::bytes_transferred
	//		, sendMemoryUnit
    //	)
    //);
}

MappedMemoryUnit* SendManager::PopMemoryUnit(_MemoryPoolIndex memoryPoolIndex) noexcept
{
	return sendMemoryPool->PopMemoryUnit(memoryPoolIndex);
}

void SendManager::PushMemory(MappedMemoryUnit* pushedMemoryUnit) noexcept
{
	sendMemoryPool->PushMemory(pushedMemoryUnit);
}
