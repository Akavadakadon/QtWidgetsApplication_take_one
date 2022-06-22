#include "QtWidgetsApplication1.h"
#include <QString>
#include <iostream>
#include "SpeedTestThreadClass.h"


QtWidgetsApplication1::QtWidgetsApplication1(QWidget* parent)
    : QMainWindow(parent)
{
    
    ui.setupUi(this);

    connect(ui.pushButton, &QPushButton::clicked, this, &QtWidgetsApplication1::btn_click);
    connect(ui.pushButton_2, &QPushButton::clicked, this, &QtWidgetsApplication1::btn2_click);
    connect(ui.pushButton_4, &QPushButton::clicked, this, &QtWidgetsApplication1::btn4_click);

    //Начало отсчета
    //connect(FFTp, SIGNAL(finished()), thread_1, SLOT(quit()));

};

//class MyQThread :public QThread
//{
//public:
//    static int counter;
//
//};
QThread* ads;
void QtWidgetsApplication1::btn_click()
{
    if (threadList.size() >= 5)
    {
        return;
    }

    QThread* thread_1;
    thread_1 = new QThread();
    threadList.push_back(thread_1);
    ads = thread_1;
    FuncForThread* FFTp = new FuncForThread(ui.lineEdit);
    AAAAAA.push_back(FFTp);
    FFTp->moveToThread(thread_1);
    connect(thread_1, &QThread::started, FFTp, &FuncForThread::process);
    connect(FFTp, &FuncForThread::someSignal, this, [this](int val) { Display(val, ui.lineEdit); });//
    //connect(FFTp, &FuncForThread::someSignal, this, &QtWidgetsApplication1::Display);//this, [this](int val) { Display(val); }
    //connect(FFTp, &FuncForThread::someSignal, this, SLOT(Display));
    //Остановка процесса через лямбда выражение https://stackoverflow.com/questions/65234783/qt-qthread-stop-when-i-need
    //connect(ui.pushButton_2, &QPushButton::clicked, [FFTp] { FFTp->stop(); });
    thread_1->start();
}
void QtWidgetsApplication1::btn2_click()
{
    if (threadList.size() == 0 )
        return;
    auto temp = threadList.front();
    auto temp1 = AAAAAA.front();
    temp1->stop();
    temp->quit();
    temp->wait();
    threadList.remove(temp);
    AAAAAA.remove(temp1);
    int asd = threadList.size();
}
void QtWidgetsApplication1::btn4_click()
{
    QThread* thread;
    thread = new QThread();
    SpeedTestThreadClass* lalalal = new SpeedTestThreadClass();
    //SpeedTestThreadClass lalalal;
    lalalal -> moveToThread(thread);
    //lalalal.moveToThread(thread);
    connect(thread, &QThread::started, lalalal, &SpeedTestThreadClass::process);
    //connect(thread, &QThread::started, &lalalal, &SpeedTestThreadClass::process);
    connect(lalalal, &SpeedTestThreadClass::updateText, this, [this](double val) { Display(val, ui.lineEdit_2); });//SLOT
    thread->start();
}
void QtWidgetsApplication1::Display(double num,QLineEdit* textBox)
{
    textBox->setText(QString::number(num)); // TODO: Свой EditLine с мютексом
}
void QtWidgetsApplication1::Display(int num)
{
    ui.lineEdit->setText(QString::number(num)); // TODO: Свой EditLine с мютексом
}

void QtWidgetsApplication1::setText(QString str)
{
    ui.lineEdit->setText(str);
}