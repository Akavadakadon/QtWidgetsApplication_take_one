//#include "CustomWindow.h"

#include <QPushButton>
#include <QApplication>
#include <QHBoxLayout>
#include "QtWidgetsApplication1.h"

class CustomWindow : public QMainWindow
{
public:
	CustomWindow() {
		QHBoxLayout* hbox = new QHBoxLayout(this);
		hbox->setSpacing(5);

		QPushButton* quitBtn = new QPushButton("Quit1", this);
		QPushButton* quitBtn1 = new QPushButton("Quit2", this);
		QPushButton* quitBtn2 = new QPushButton("Quit3", this);
		hbox->addWidget(quitBtn);
		hbox->addWidget(quitBtn1);
		hbox->addWidget(quitBtn2);

		connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);
	}
};