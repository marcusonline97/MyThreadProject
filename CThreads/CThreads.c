// CThreads.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Resourse link for process threads Api is down below
// https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-createthread
//#include <iostream> i dont need iostream since i am utilizing C (will try to make it work in C++ eventually)

#include <stdio.h>
#include<Windows.h>

volatile int globalCounter = 0; //My loop start number
const int limit = 100000000; //My Loop end number

CRITICAL_SECTION semapthorXXX; //Declaring the semapthorxxx as a critical Section
//
void* func(void* var)
{
    DWORD threadID = GetCurrentThreadId();

    while (globalCounter < limit) //Perform until it's the same amount
    {
        Sleep(2); //Not required but just keept for testing

        EnterCriticalSection(&semapthorXXX); //this helps keep manage and synqronize my threads 
        //Along with LeveCriticalSection which keeps them in synq
        globalCounter++; //Increases my starter int by 1

        printf("[%6i], Counter: %i\n", threadID, globalCounter);
        LeaveCriticalSection(&semapthorXXX);  
    }
    return NULL; //We want nothing returned once the program is finished so we tell it to return
    // nothing when done.
}

int main() //My main function
{
    InitializeCriticalSection(&semapthorXXX); //Initializing my section

    for (size_t i = 0; i < 50; i++)
    {
        CreateThread //Creates our thread 
        (
            NULL,
            NULL,
            func,
            NULL,
            0,
            NULL
        );
    }

    while (1)
    {
    }
    return 1; //The return code to end the program
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
