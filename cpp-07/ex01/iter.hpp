#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T, typename Func>
void iter(T *array, size_t length, Func f)
{
	if (!array || !f)
		return;
	for (size_t i = 0; i < length; i++)
	{
		f(array[i]);
	}
}

#endif
