#pragma once

#include <iostream>
// ������������������ ����� ���������

#ifdef SOMELIBRARY_EXPORTS
#define SOMELIBRARY_API __declspec(dllexport)
#else
#define SOMELIBRARY_API __declspec(dllimport)
#endif

// ������������� ������������������
extern "C" SOMELIBRARY_API void fib_init(unsigned long long x, unsigned long long y);

extern "C" SOMELIBRARY_API bool fib_next();

extern "C" SOMELIBRARY_API unsigned long long fib_current();

extern "C" SOMELIBRARY_API unsigned int fib_index();

extern "C" SOMELIBRARY_API void say_something();
