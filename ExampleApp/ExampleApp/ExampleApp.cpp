#include <iostream>
#include "ExampleLibrary.h"

int main()
{
    fib_init(1, 1);
    for (size_t i = 0; i < 10; ++i)
    {
        if (fib_next())
        {
            std::cout << fib_index() << " - " << fib_current() << std::endl;
        }
    }
    say_something();
    system("pause");
    return 0;
}
