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
#include <thread>
#include "NumberManipulations.h"
#include "CalculationTerminal.h"


/**
* @brief Main Window of Intermod GUI
* 
* This class is meant to contain all code, variables and buttons relating to the main window of the GUI
* 
* @author Larry Staecey & Raymond Bedry, RTP, E-Division, RCMP
*/
class Intermod : public QMainWindow
{
	Q_OBJECT

public:
	Intermod(QWidget* parent = Q_NULLPTR);

public slots:
	void showProgress(int progress);
	void setMaxProgress(int max);

protected:
	QPoint oldPos;
	/** @brief 
	*
	*
	*	@param eventType 
	*	@param message 
	*	@param result
	*
	*	@return 
	*/
	bool nativeEvent(const QByteArray& eventType, void* message, long* result) override;
	/** @brief Function that assits in the event of a button on the mouse being pressed. 
	*
	*
	*	@param event
	*
	*	@return 
	*/
	virtual void mousePressEvent(QMouseEvent* event);
	/** @brief Function that assists in the viewing of the mouse cursor over the window
	*
	*
	*	@param event 
	*
	*	@return nothing to return
	*/
	virtual void mouseMoveEvent(QMouseEvent* event);

private:
	Ui::IntermodClass ui; ///Instantiation of intermod class ui
	OutputClass *output;
	CalculationTerminal *Calculate;
	/** @brief Function that will retrieve values for intermodulation calculation from the interface.
	*
	*	This function will retrieve all transmitter and receiver values from the main interface and will input them into the correct vectors. Will
	*	also retrieve project title and ensure that inputs are in the correct format and have the right characters input.
	*
	*	@return nothing to return
	*/
	void getIntermodValues();
	/** @brief Function that will clear all inputs from the interface
	*
	*	This function will clear table to a new slate and double check with the user that this was the desired action.
	*
	*	@param confirm A double check to ensure that the user wants to erase the table.
	*
	*	@return nothing to return
	*/
	void clearValues(bool confirm = false);
	/** @brief Function that will display confirmation message to the user
	*
	*	This function will clear table to a new slate and double check with the user that this was the desired action.
	*
	*	@param msg A double check to ensure that the user wants to erase the table.
	*	@param yesNo 
	*
	*	@return nothing to return
	*/
	bool messageIndicate(QString msg, bool yesNo = false);
	void showOutput();
	void showHelp();
	void showAbout();
	void minimizeWindow();
	void maximizeWindow();
	void closeWindow();
	void saveInputs();
	void loadInputs();
};

