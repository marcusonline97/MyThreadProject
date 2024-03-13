// CThreads.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Resourse link for process threads Api is down below
// https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-createthread
//#include <iostream> i dont need iostream since i am utilizing C (will try to make it work in C++ eventually)

#include <stdio.h>
#include<Windows.h>

volatile int globalCounter = 0; //My loop start number
const int limit = 100000000; //My Loop end number

CRITICAL_SECTION semapthor; //Declaring the semapthorxxx as a critical Section
//
void* func(void* var)
{
    DWORD threadID = GetCurrentThreadId();

    while (globalCounter < limit) //Perform until it's the same amount
    {
        Sleep(2); 
        EnterCriticalSection(&semapthor); //this helps keep manage and synqronize my threads 
        //Along with LeveCriticalSection which keeps them in synq
        globalCounter++; //Increases my starter int by 1

        printf("[%6i], Counter: %i\n", threadID, globalCounter);
        LeaveCriticalSection(&semapthor);  
    }
    return NULL; //We want nothing returned once the program is finished so we tell it to return
    // nothing when done.
}

int main() 
{
    InitializeCriticalSection(&semapthor); 
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