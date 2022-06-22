#include "SpeedTestThreadClass.h"


void SpeedTestThreadClass::process()
{
    //run = true;
    speed = 0;
    //while (run || )
    auto ckech1 = AtomicCounter::Get();
    for(int i=0;i< count || run; i++)
    {
        QThread::msleep(interval);
        auto ckech2 = AtomicCounter::Get();
        speed = (double)(ckech2 - ckech1) / (interval*(i+1)) * interval;
        emit SpeedTestThreadClass::updateText(speed);
    }
}
void SpeedTestThreadClass::stop()
{

}

SpeedTestThreadClass::SpeedTestThreadClass()
{
    run = false;
    interval=1000;
    count=5;
}