#pragma once

#include <QWidget>
#include "ui_OutputClass.h"
#include <vector>
#include <fstream>
#include <QtCharts>
#include <regex>
#include <QPrinter>
#include <QPrintDialog>
#include "NumberManipulations.h"

class OutputClass : public QWidget
{
	Q_OBJECT

public:
	OutputClass(QWidget *parent = Q_NULLPTR);
	~OutputClass();
	void setHTML();
	QString createOutputHTML(std::vector<float> resultList, std::vector<std::string> eqList, std::vector<float> rxList, std::vector<float> txList, std::vector<QString> nameList, int order, float range, std::vector<int> orderVector);
	
	std::vector<float> txVector;
	std::vector<float> rxVector;
	std::vector<QString> nVector;
	int maxOrder;
	float calcRange;

protected:
	QPoint oldPos;
	bool nativeEvent(const QByteArray& eventType, void* message, long* result) override;
	virtual void mousePressEvent(QMouseEvent* event);
	virtual void mouseMoveEvent(QMouseEvent* event);

private:
	Ui::OutputClass ui;

	QString htmlFile;

	QString drawGraph(std::vector<float> resultList, std::vector<float> rxList, std::vector<float> txList, std::vector<QString> nameList);
	void closeWindow();
	void saveToFile();
	void printHTML();

	
	
};
