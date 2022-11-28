#include <iostream>
#include <chrono>
#include <Windows.h>

int main()
{
    bool BLM = false;
    size_t n = 0;
    int* arr = new int[n];
    for (size_t i = 0; i < n; ++i) arr[i] = 0;
    while (true)
    {
        std::cout << "Echo." << std::endl;
        Sleep(1000);
    }
    delete[] arr;
    return 0;
}
