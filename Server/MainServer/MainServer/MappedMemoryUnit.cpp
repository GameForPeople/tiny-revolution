#include "stdafx.h"

#include "MappedMemoryUnit.h"

namespace WonSY_SERVER 
{
	MappedMemoryUnit::MappedMemoryUnit(_MemoryPoolIndex memoryPoolIndex) noexcept
		: buffer()
		, memoryPoolIndex(memoryPoolIndex)
	{
	}
}