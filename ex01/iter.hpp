#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>

void iter(T array[], int size, void func(T const &))
{
	if(func != NULL)
	{
		for (int i = 0; i < size; i++)
			func(array[i]);
	}
}

template <typename T>
void func(T const &element)
{
	if(element)
		std :: cout << element << std :: endl;

}
#endif