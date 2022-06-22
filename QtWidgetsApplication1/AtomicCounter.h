#pragma once
#include <atomic>

//std::atomic<int> number = 0;

class AtomicCounter // AtomicCounter::Append2
{
private:
public:
    static std::atomic<int> number;
    AtomicCounter();
    static int Get();
    static void Set(int num);
    static int Append1();
    static int Append2();
};
