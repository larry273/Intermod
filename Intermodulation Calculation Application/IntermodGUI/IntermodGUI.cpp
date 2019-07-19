#include "IntermodGUI.h"
#include <iostream>
#include <fstream>
#include <QDebug>
#include <vector>
#include <QMessageBox>

using namespace std;

Intermod::Intermod(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	output = new OutputClass();

	//stretch all columns of the table widget evenly
	QHeaderView* header = ui.tableWidget->horizontalHeader();
	header->setSectionResizeMode(QHeaderView::Stretch);
	Intermod::clearValues();

	QTableWidget* table = ui.tableWidget;
	for (int i = 0; i < 9; i++) {
		table->insertRow(table->rowCount());
	}

	//connect button push to calculate intermod
	connect(ui.calculateButton, &QPushButton::clicked, this, &Intermod::getIntermodValues);
	connect(ui.clearButton, &QPushButton::clicked, this, [this]() {Intermod::clearValues(true);});
	connect(ui.helpButton, &QPushButton::clicked, this, &Intermod::showHelp);

}
//get the values for intermod calculation from the interface
void Intermod::getIntermodValues() {
	qDebug() << "-- Intermod calculation values from interface -- ";
	//ui.calculateButton->setText("Here");

	QString name;
	QString sRxFreq;
	QString sTxFreq;

	//Get range and order from interface
	int freqRange = ui.searchLine->text().toInt();
	QString orderText = ui.orderBox->currentText();
	if (orderText.length() > 9) {
		orderText = orderText.left(2);
	}
	else {
		orderText = orderText.left(1);
	}
	int order = orderText.toInt();
	qDebug() << "Max Order: " << order << "Frequency Range: " << freqRange;

	QRegExp re("\\d*"); //digits regular expression
	vector<QString> nameVector;
	vector<vector<double>> freqVector;

	//iterate through table to get rx and tx frequences and names associated 
	for (int row = 0; row < ui.tableWidget->rowCount(); row++) {
		vector<double> freqV;
		for (int column = 0; column < ui.tableWidget->columnCount(); column++) {
			//qDebug() << 'Row ' << row << ":" << "Column " << column;

			//upon reaching a blank cell break
			QTableWidgetItem* item(ui.tableWidget->item(row, column));
			if (!item) {
				break;
			}


			if (column == 0) {
				qDebug() << "Name: " << ui.tableWidget->item(row, column)->text();
				name = ui.tableWidget->item(row, column)->text();
				nameVector.push_back(name);
			}
			else if (column == 1) {
				qDebug() << "Tx Freq: " << ui.tableWidget->item(row, column)->text();
				sTxFreq = ui.tableWidget->item(row, column)->text();
				//Check input against regular expression
				if (!re.exactMatch(sTxFreq)) {
					Intermod::messageIndicate("Frequency values must be a number ");
					return;
				}
					
				double txFreq = sTxFreq.toDouble();
				freqV.push_back(txFreq);
			}
			else if (column == 2) {
				qDebug() << "Rx Freq: " << ui.tableWidget->item(row, column)->text();
				sRxFreq = ui.tableWidget->item(row, column)->text();
				//Check input against regular expression
				if (!re.exactMatch(sTxFreq)) {
					Intermod::messageIndicate("Frequency values must be a number ");
					return;
				}
				double rxFreq = sTxFreq.toDouble();
				freqV.push_back(rxFreq);
			}
			if (freqV.size() == 2) {
				freqVector.push_back(freqV);
				freqV.clear();

			}
		}
	}

	Intermod::showOutput();
}

//clear table of frequency values
void Intermod::clearValues(bool confirm){
	if (confirm) {
		bool result;
		QString msg = "Are you sure you want to clear the table?";
		result = Intermod::messageIndicate(msg, true);

		if (!result) {
			return;
		}
	}
	//delete all rows, then reset to normal amount of rows
	ui.tableWidget->setRowCount(0);
	ui.tableWidget->setRowCount(10);
}

//display message to the user
bool Intermod::messageIndicate(QString msg, bool yesNo) {
	//show a yes no prompt on the message box
	if (yesNo) {
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, " ", msg,
			QMessageBox::Yes | QMessageBox::No );
		if (reply == QMessageBox::Yes) {
			qDebug() << "Yes was clicked";
			return 1;
		}
		else if (reply == QMessageBox::No)
		{
			qDebug() << "No was clicked";
			return 0;
		}
	}
	//only show a message to the user
	else {
		QMessageBox::information(this, " ", msg);
		return 1;
	}
}

void Intermod::showHelp() {
	QString helpmsg =
		"How to use the RF Intermodulation Calculator:\n\n"
		"1. Input a name, recieving frequency and transmitting frequency for each frequency to be tested for intermodulation.\n"
		"2. Select the cutoff order and search window for the calculation.\n"
		"3. Press the \"Calculate\" button to run the calculation and produce an output report.\n\n"
		"The output reports can be saved and re-opened.";
	Intermod::messageIndicate(helpmsg);
}

//show and hide the output window
void Intermod::showOutput(){
	if (output->isVisible()) {
		output->hide();
	}
	else {
		output->show();
		//calculate stuff here
		output->setHTML();
	}

}