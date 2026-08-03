#include "Serializer.hpp"


uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

/* !If you try to use static_cast to turn a Data* into an integer, the C++ compiler will throw an error. Logically, a memory address is not a math number, so static_cast refuses to do it.

This is where reinterpret_cast comes in. It tells the compiler: "I know these two types have absolutely nothing in common, but I want you to take the exact bits in memory and just pretend they are this other type."*/
