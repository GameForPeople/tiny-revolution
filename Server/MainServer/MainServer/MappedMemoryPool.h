#pragma once

namespace WonSY 
{
	template <typename _MappedMemoryType>
	class MappedMemoryPool
	{
	public:
		enum class CONSTRUCTOR_POSITION
		{
			SEND_MEMORY_MANAGER
		};

		enum class MEMORY_POOL_MAPPED_SIZE : _MemoryPoolIndex
		{
			SEND_MEMORY_POOL = 10
		};

		enum class MEMORY_UNIT_COUNT : unsigned int
		{
			SEND_MEMORY_POOL = 100000
		};

	public:
		MappedMemoryPool(CONSTRUCTOR_POSITION, MEMORY_POOL_MAPPED_SIZE, MEMORY_UNIT_COUNT);

		void PushMemory(_MappedMemoryType*) noexcept;
		_NODISCARD _MappedMemoryType* PopMemoryUnit(_MemoryPoolIndex) noexcept;

	private:
		vector<concurrent_queue<_MappedMemoryType*>> memoryPoolCont;
	};
}

#include "MappedMemoryPool.hpp"