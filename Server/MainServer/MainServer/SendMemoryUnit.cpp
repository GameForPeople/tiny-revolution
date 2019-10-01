#include "stdafx.h"
#include "SendMemoryUnit.h"

SendMemoryUnit::SendMemoryUnit(_MemoryPoolIndex memoryPoolIndex) noexcept
	: buffer()
	, sendMemoryPoolIndex(memoryPoolIndex)
{
}