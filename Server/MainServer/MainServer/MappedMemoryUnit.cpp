#include "stdafx.h"

#include "MappedMemoryUnit.h"

MappedMemoryUnit::MappedMemoryUnit(_MemoryPoolIndex memoryPoolIndex) noexcept
	: buffer()
	, memoryPoolIndex(memoryPoolIndex)
{
}