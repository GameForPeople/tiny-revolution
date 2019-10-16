#include "stdafx.h"

#include "MappedMemoryUnit.h"

namespace WonSY 
{
	MappedMemoryUnit::MappedMemoryUnit(_MemoryPoolIndex memoryPoolIndex) noexcept
		: buffer()
		, memoryPoolIndex(memoryPoolIndex)
	{
	}
}