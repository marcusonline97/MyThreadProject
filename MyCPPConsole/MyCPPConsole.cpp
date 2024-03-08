// MyCPPConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

ull OddSum = 0;
ull EvenSum = 0;

void findEven(ull start, ull end)
{
    for (ull i = start; i <= end; ++i)
    {
        if ((i & 1) == 0)
        {
            EvenSum += i;
        }
    }
}

void findOdd(ull start, ull end)
{
    for (ull i = start; i <= end; ++i)
    {
        if ((i & 1) == 1)
        {
            OddSum += i;
        }
    }
}
int main()
{
    ull start = 0, end = 1900000000;

    auto startTime = high_resolution_clock::now();

    std::thread

    findOdd(start, end);
    findEven(start, end);



}