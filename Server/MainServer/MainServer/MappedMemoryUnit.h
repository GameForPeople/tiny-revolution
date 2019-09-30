#pragma once

struct MappedMemoryUnit
{
	std::array<_DataType, NETWORK::RECV_BUFFER_MAX_SIZE> buffer;
	_MemoryPoolIndex memoryPoolIndex;

public:
	MappedMemoryUnit(_MemoryPoolIndex memoryPoolIndex) noexcept;
};