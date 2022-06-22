#pragma once
#include <QString>
#include <QObject>
#include <QThread>
#include <QLineEdit>
#include "AtomicCounter.h"
//func to start thread
class FuncForThread : public QObject
{
    Q_OBJECT
private:
    QString qStr;
    QLineEdit* qle;
    bool run;
public slots:
    void process();
    void stop();
public:
    FuncForThread(QLineEdit* _qle);
    ~FuncForThread();
    //AtomicCounter cc;
signals:
    void finished();
    void updateText(const QString&);
    void someSignal(int counter);
};