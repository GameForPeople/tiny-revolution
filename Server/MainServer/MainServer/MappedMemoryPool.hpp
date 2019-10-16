namespace WonSY
{
	template <typename _MappedMemoryType>
	MappedMemoryPool<_MappedMemoryType>::MappedMemoryPool(CONSTRUCTOR_POSITION, MEMORY_POOL_MAPPED_SIZE memoryPoolSize, MEMORY_UNIT_COUNT memoryUnitCount)
	{
		auto tempMemoryPoolSize = static_cast<_MemoryPoolIndex>(memoryPoolSize);
		auto tempMemoryUnitCount = static_cast<unsigned int>(memoryUnitCount);

		memoryPoolCont.reserve(tempMemoryPoolSize);
		for (int i = 0; i < tempMemoryPoolSize; ++i) { memoryPoolCont.emplace_back(); }

		_MappedMemoryType* tempMemoryType;
		for (int i = 0; i < tempMemoryPoolSize; ++i)
		{
			for (int j = 0; j < tempMemoryUnitCount; ++j)
			{
				tempMemoryType = new _MappedMemoryType(i);
				memoryPoolCont[i].push(tempMemoryType);
			}
		}
	}

	template <typename _MappedMemoryType>
	void MappedMemoryPool<_MappedMemoryType>::PushMemory(_MappedMemoryType* memoryUnit) noexcept
	{
		memoryPoolCont[memoryUnit->memoryPoolIndex].push(memoryUnit);
	}

	template <typename _MappedMemoryType>
	_MappedMemoryType* MappedMemoryPool<_MappedMemoryType>::PopMemoryUnit(_MemoryPoolIndex memoryPoolIndex) noexcept
	{
		_MappedMemoryType* retMemoryUnit{ nullptr };
		while (!memoryPoolCont[memoryPoolIndex].try_pop(retMemoryUnit))
		{
			std::cout << "memory Pool의 메모리가 부족합니다. \n";
		}
		return retMemoryUnit;
	}
}