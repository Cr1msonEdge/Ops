#include <limits.h>
#include <utility>
#include "ExampleStaticLibrary.h"

static unsigned long long curr;
static unsigned long long prev;
static unsigned int ind;
char bigarray[5 * 1024 * 1024] = { 1 };

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
	for (size_t i = 0; i < 5 * 1024 * 1024; ++i)
	{
		++bigarray[i];
	}
	std::cout << "Something." << std::endl;
	//std::cout << "Anything." << std::endl;
}
