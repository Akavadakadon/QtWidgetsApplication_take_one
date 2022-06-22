#include "FuncForThread.h"


void FuncForThread::process()
{
    while (1 && run)
    {
        //qle->setText(QString::number(counter)); // TODO: Свой EditLine с мютексом
        QThread::msleep(10);
        auto a = AtomicCounter::Append1();
        emit someSignal(a);
        //emit updateText(QString::number(counter));
    }
}
void FuncForThread::stop() 
{
    run = false;
}
FuncForThread::FuncForThread(QLineEdit* _qle)
{
    run = true;
    qle = _qle;
    qStr;
}
FuncForThread::~FuncForThread()
{

}