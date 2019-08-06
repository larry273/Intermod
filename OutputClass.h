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
/**
* @brief Output Window of Intermod GUI
*
* This class is meant to contain all code, variables and buttons relating to the output window of the GUI
*
* @author Larry Staecey & Raymond Bedry, RTP, E-Division, RCMP
*/
class OutputClass : public QWidget
{
	Q_OBJECT

signals:
	void progressSignal(int progress);

public:
	OutputClass(QWidget *parent = Q_NULLPTR);
	~OutputClass();
	void setHTML();
	QString createOutputHTML(
		std::vector<float> resultList, 
		std::vector<std::string> eqList, 
		std::vector<float> rxList, 
		std::vector<float> txList, 
		std::vector<QString> nameList, 
		int order, 
		float range, 
		std::vector<int> orderList, 
		std::vector<std::vector<float>> hitList
	);
	
	std::vector<float> txVector;
	std::vector<float> rxVector;
	std::vector<QString> nameVector;

	std::vector<float> resultVector;
	std::vector<std::string> equationVector;
	std::vector<std::vector<float>> hitVector;
	std::vector<int> orderVector;

	int maxOrder;
	float calcRange;
	QString projectTitle;
	int progress;

protected:
	QPoint oldPos;
	bool nativeEvent(const QByteArray& eventType, void* message, long* result) override;
	virtual void mousePressEvent(QMouseEvent* event);
	virtual void mouseMoveEvent(QMouseEvent* event);

private:
	Ui::OutputClass ui;

	QString htmlFile;

	QString drawGraph(std::vector<float> resultList, std::vector<float> rxList, std::vector<float> txList, std::vector<QString> nameList, std::vector<int> orderList, int order);
	void closeWindow();
	void saveToFile();

};
