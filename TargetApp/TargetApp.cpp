#include <iostream>
#include <chrono>
#include <Windows.h>
int main()
{
    while (true)
    {
        std::cout << "Echo." << std::endl;
        Sleep(1000);
    }
    return 0;
}
