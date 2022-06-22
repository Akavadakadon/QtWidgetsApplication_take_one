#pragma once

#include <QtWidgets/QMainWindow>
#include <QThread>//QLineEdit 
#include <QLineEdit>//
#include <list>//
#include "ui_QtWidgetsApplication1.h"
#include "FuncForThread.h"

class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication1(QWidget *parent = Q_NULLPTR);
    void Display(int num);
    void Display(double num, QLineEdit* textBox);

private slots:
    void btn_click();
    void btn2_click();
    void btn4_click();
    void setText(QString str);
private:
    Ui::QtWidgetsApplication1Class ui;

    QLineEdit* line_1;
    QLineEdit* line_2;

    std::list<QThread*> threadList;
    std::list<FuncForThread*> AAAAAA;

    
    int count_1;
    int count_2;
};
