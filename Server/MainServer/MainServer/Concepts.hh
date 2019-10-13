#pragma once

#ifdef __cpp_lib_concepts
template<typename _Type>
concept CONCEPT_MAPPEDMEMORY = requires(_Type type)
{
	{type.MemoryPoolIndex()} -> const unsigned int;
};
#endif