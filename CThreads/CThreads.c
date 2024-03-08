// CThreads.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
#include <stdio.h>
#include<Windows.h>

volatile int globalCounter = 0;
const int limit = 100000000;

CRITICAL_SECTION semapthorXXX;

void* func(void* var)
{
    DWORD threadID = GetCurrentThreadId();

    while (globalCounter < limit)
    {
        Sleep(2);

        EnterCriticalSection(&semapthorXXX);
        globalCounter++;

        printf("[%6i], Counter: %i\n", threadID, globalCounter);
        LeaveCriticalSection(&semapthorXXX);  
    }
    return NULL;
}

int main()
{
    InitializeCriticalSection(&semapthorXXX);

    for (size_t i = 0; i < 50; i++)
    {
        CreateThread
        (
            NULL,
            NULL,
            func,
            NULL,
            0,
            NULL
        );
    }

  
  

    //std::cout << "Hello World!\n";
    while (1)
    {
    }
    return 1;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
