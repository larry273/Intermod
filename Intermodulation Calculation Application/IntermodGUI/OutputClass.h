#pragma once

#include <QWidget>
#include "ui_OutputClass.h"
#include <vector>


class OutputClass : public QWidget
{
	Q_OBJECT

public:
	OutputClass(QWidget *parent = Q_NULLPTR);
	~OutputClass();
	void setHTML();
	QString createOutputHTML(std::vector<double>  resultList, std::vector<std::string> eqList, std::vector<std::vector<double>> freqList, std::vector<QString> nameList, int order, int range, std::vector<int> orderVector);

private:
	Ui::OutputClass ui;
	QString htmlFile;
	QString drawGraph(std::vector<double> resultList);
	void closeWindow();
	void saveToFile();
	void printHTML();
};
