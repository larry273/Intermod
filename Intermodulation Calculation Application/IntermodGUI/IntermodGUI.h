#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_IntermodGUI.h"
#include "OutputClass.h"


class Intermod : public QMainWindow
{
	Q_OBJECT

public:
	Intermod(QWidget* parent = Q_NULLPTR);
	//private slots:
		//void calculateIntermod();


private:
	Ui::IntermodClass ui;
	OutputClass *output;
	void getIntermodValues();
	void clearValues(bool confirm = false);
	bool messageIndicate(QString msg, bool yesNo = false);
	void showOutput();
	void showHelp();
};

