#include "pch.h"
#include <limits.h>
#include <utility>
#include "ExampleLibrary.h"

static unsigned long long curr;
static unsigned long long prev;
static unsigned int ind;


void fib_init(unsigned long long x, unsigned long long y)
{
	ind = 0;
	curr = x;
	prev = y;
}

bool fib_next()
{
	if ((UINT_MAX == ind) || (ULLONG_MAX - prev) < curr)  // проверка на переполнение
	{
		return false;
	}

	if (ind > 0)
	{
		prev += curr;
	}

	std::swap(curr, prev);
	++ind;
	return true;
}

unsigned long long fib_current()
{
	return curr;
}

unsigned int fib_index()
{
	return ind;
}

void say_something()
{
	std::cout << "Something." << std::endl;
	std::cout << "Anything." << std::endl;
}