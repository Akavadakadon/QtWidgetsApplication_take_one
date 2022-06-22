#pragma once
#include <QThread>
#include <QObject>
#include "AtomicCounter.h"

class SpeedTestThreadClass : public QObject
{
    Q_OBJECT

private:
    int interval;
    int count;
    bool run;
    double speed;
public slots:
    void process();
    void stop();
public:
    SpeedTestThreadClass();
signals:
    void finished();
    void updateText(double speed);



};

