#pragma once

#include <QtWidgets/QMainWindow>
#include <QWidget>
#include "ui_IntermodGUI.h"
#include "OutputClass.h"
#include <iostream>
#include <fstream>
#include <QDebug>
#include <vector>
#include <QMessageBox>
#include <QMouseEvent>
#include <windows.h>
#include "NumberManipulations.h"
#include "CalculationTerminal.h"

class Intermod : public QMainWindow
{
	Q_OBJECT

public:
	Intermod(QWidget* parent = Q_NULLPTR);
	//private slots:
		//void calculateIntermod();

protected:
	QPoint oldPos;
	bool nativeEvent(const QByteArray& eventType, void* message, long* result) override;
	virtual void mousePressEvent(QMouseEvent* event);
	virtual void mouseMoveEvent(QMouseEvent* event);

private:
	Ui::IntermodClass ui;
	OutputClass *output;
	CalculationTerminal *Calculate;
	void getIntermodValues();
	void clearValues(bool confirm = false);
	bool messageIndicate(QString msg, bool yesNo = false);
	void showOutput();
	void showHelp();
	void minimizeWindow();
	void maximizeWindow();
	void closeWindow();
};

