#include "AtomicCounter.h"

std::atomic<int> AtomicCounter::number = 0;

AtomicCounter::AtomicCounter() 
{

}
int AtomicCounter::Get() 
{

	return number.load();
}
void AtomicCounter::Set(int num)
{

}
int AtomicCounter::Append1()
{
	//number.load();
	number.fetch_add(1);
	return number.load();
}
int AtomicCounter::Append2()
{
	return 1;
}
