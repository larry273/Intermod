#include "OutputClass.h"
#include <fstream>
#include <QtCharts>
#include <regex>
#include <QPrinter>
#include <QPrintDialog>


OutputClass::OutputClass(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//button connections in the ui
	connect(ui.closeButton, &QPushButton::clicked, this, &OutputClass::closeWindow);
	connect(ui.saveButton, &QPushButton::clicked, this, &OutputClass::saveToFile);
	connect(ui.printButton, &QPushButton::clicked, this, &OutputClass::printHTML);

}

//accept input of calculation and create the ouput temporary html output
QString OutputClass::createOutputHTML(std::vector<double> resultList, std::vector<std::string> eqList, std::vector<std::vector<double>> freqList, std::vector<QString> nameList, int order, int range, std::vector<int> orderVector) {
	//read sample html file for default layout
	std::ifstream infile("default.html");
	std::string content((std::istreambuf_iterator<char>(infile)),
		(std::istreambuf_iterator<char>()));
	QString html = QString::fromStdString(content);

	//define ending on order
	QString orderTh;
	if (order == 1) { orderTh = "st"; }
	else if (order == 2) { orderTh = "nd"; }
	else if (order == 3) { orderTh = "rd";  }
	else { orderTh = "th"; }

	//get current date
	QDateTime date = QDateTime::currentDateTime();
	QString sDate = date.toString("MMMM dd yyyy");

	//replace in html order, date, and range
	QString sOrder = QString::number(order);
	QString sRange = QString::number(range);
	html.replace("ORDER", sOrder + orderTh);
	html.replace("RANGE", sRange);
	html.replace("DATE", sDate);

	//html block for each frequency name, rx and tx
	std::string freqValue =
		"<tr> \n"
		"<td width = \"33%\"><H3>FREQNAME</H3></td>\n"
		"<td width = \"33%\"><H3>FREQRX</H3></td>\n"
		"<td width = \"33%\"><H3>FREQTX</H3></td>\n"
		"</tr>\n";
	QString sFreqValue = QString::fromStdString(freqValue);
	int index = html.indexOf("<!--FREQLIST-->");
	for (int i = nameList.size() - 1; i >= 0 ; i--) {
		QString name = nameList[i];
		QString rx = QString::number(freqList[i][0]);
		QString tx = QString::number(freqList[i][1]);

		QString s = sFreqValue;
		s.replace("FREQNAME", name);
		s.replace("FREQRX", rx);
		s.replace("FREQTX", tx);

		html.insert(index, s);
	}
	
	int orderIndex = html.indexOf("<!--HITCATEGORY-->");
	int orderInter = order;
	//Loop through index vector for each order
	for (int k = orderVector.size() - 1; k >= 0; k--) { //vector of indexes for result, loop backwards
		//html block for each order
		QString sOrderBlock =
			"<H1 class=\"topInfo\" style=\"text-align:left\">ORDERTEXT Order Harmonics:</H1>\n"
			"<table class = \"freqValue\" id = \"tableBG\" width = \"100%\">\n"
			"<tr>\n"
			"<th width = \"40%\"><H2>Intermodulation Freq</H2></th>\n"
			"<th width = \"60%\"><H2>Intermodulation Equation</H2></th>\n"
			"</tr>\n"
			"<!--HITLIST-->\n"
			"</table>\n";
		int reIndex = orderVector[k];

		//turn iterating order into Xth text for output
		QString orderInterTh;
		if (orderInter == 1) { orderInterTh = "st"; }
		else if (orderInter == 2) { orderInterTh = "nd"; }
		else if (orderInter == 3) { orderInterTh = "rd"; }
		else { orderInterTh = "th"; }
		QString o = QString::number(orderInter);
		sOrderBlock.replace("ORDERTEXT", o + orderTh);
		
		//html block for each equation, freq, range
		QString sResultValue =
			"<tr>\n"
			"<td width = \"40%\"><H3>FREQ</H3></td>\n"
			"<td width = \"60%\"><H3>EQUATION</H3></td>\n"
			"</tr>\n";
		index = sOrderBlock.indexOf("<!--HITLIST-->");
		QString hertz = " MHz";
		int orderInter = orderInter - 2;

		//add a table line for each product and output for that order
		for (int i = reIndex; i >= 0; i--) {
			std::string e = eqList[i];
			QString eq = QString::fromStdString(e);

			QString f = QString::number(resultList[i]);
			QString s = sResultValue;
			s.replace("EQUATION", eq);
			s.replace("FREQ", f + hertz);

			sOrderBlock.insert(index, s);
		}
		//insert order block into html string
		html.insert(orderIndex, sOrderBlock);
	}
	//final html to ouput
	std::string htmlOutput = "string";
	return html;
}

//set the html output into the output window 
void OutputClass::setHTML() {
	//parse outputs values into html
	int o = 3;
	int r = 100;
	std::vector<std::string> eq = { "2*444 + 1*555 = 777", "1*444 + 2*555 = 888", "1*444 + 2*555 = 888", "1*444 + 2*555 = 888" };
	std::vector<QString> nList = { "Freq1Inserted", "Freq2Inserted" };
	std::vector<std::vector<double>> fList = { {444,444}, {555,555} };
	std::vector<double> rList = { 402.1, 403.2, 402.3, 404.5 };
	std::vector<int> indexR = { 3 };

	QString html;
	html = OutputClass::createOutputHTML(rList, eq, fList, nList, o, r, indexR);

	//draw graph to base64 and set into html
	QString graph;
	graph = OutputClass::drawGraph(rList);
	QString graph64= "\"data:image/png;base64, " + graph + "\"";
	html.replace("IMAGEBASE64", graph64);

	//set viewer html from created html
	ui.htmlView->setHtml(html);
	OutputClass::htmlFile = html;
}


QString OutputClass::drawGraph(std::vector<double> resultList) {
	
	//TODO method accept result vector, and input vector and loop through them creating graph series
	QChart* chart = new QChart();

	//X axis for the graph
	QValueAxis* axisX = new QValueAxis();
	axisX->setRange(380, 410);
	axisX->setTitleText("Frequency (MHz)");
	axisX->setLabelsBrush(QBrush(Qt::white));
	axisX->setTitleBrush(QBrush(Qt::white));
	chart->addAxis(axisX, Qt::AlignBottom);

	//y axis for the graph
	QValueAxis* axisY = new QValueAxis();
	axisY->setRange(0, 5.5);
	axisY->setTickType(QValueAxis::TicksDynamic);
	axisY->setTickInterval(1);
	axisY->setLabelsVisible(false);
	axisY->setTitleText("Amplitude");
	axisY->setLabelsBrush(QBrush(Qt::white));
	axisY->setTitleBrush(QBrush(Qt::white));
	chart->addAxis(axisY, Qt::AlignLeft);

	for (int i = 0; i < resultList.size(); i++) {
		double vector = resultList[i];

		QLineSeries* series = new QLineSeries();
		series->setName("Freq " + i );
		*series << QPointF(vector, 0) << QPointF(vector, 5);

		chart->addSeries(series);
		//set graphing line thickness
		QPen pen = series->pen();
		pen.setWidth(12);
		series->setPen(pen);

		//attach axis to each series
		series->attachAxis(axisX);
		series->attachAxis(axisY);
	}

	QFont font;
	font.setPixelSize(18);
	chart->setTitleFont(font);
	chart->setTitle("Intermodulation Products");
	chart->setTitleBrush(QBrush(Qt::white));

	//show graph legend
	chart->legend()->setVisible(true);
	chart->legend()->setAlignment(Qt::AlignBottom);
	chart->legend()->setLabelBrush(QBrush(Qt::white));
	
	//setbackground colors
	chart->setPlotAreaBackgroundBrush(QBrush(QColor::fromRgb(63, 70, 77)));
	chart->setPlotAreaBackgroundVisible(true);
	chart->setBackgroundBrush(QBrush(QColor::fromRgb(40, 44, 48)));

	QChartView *chartView = new QChartView(chart);
	chartView->setRenderHint(QPainter::Antialiasing);
	chartView->resize(650, 450);
	
	//save graph into a bytes array encoded as base64
	QByteArray byteArray;
	QBuffer buffer(&byteArray);

	//save the chart as a base64 buffer to display in html
	QPixmap p = chartView->grab();
	p.save(&buffer, "PNG");
	QString imageBase64 = QString::fromLatin1(byteArray.toBase64().data());
	//qDebug() << "Output graph saved to base64" << imageBase64 ;
	return imageBase64;
}

//close the output window
void OutputClass::closeWindow() {
	OutputClass::hide();
}

//Save html output to a file, default to documents folder
void OutputClass::saveToFile() {
	//open dialog to save to a location
	QString documents = QStandardPaths::locate(QStandardPaths::DocumentsLocation, QString(), QStandardPaths::LocateDirectory);

	QString fileName = QFileDialog::getSaveFileName(this, tr("Save Intermodulation Output"),
		documents + "intermodOutput.html",
		tr("Intermod Output (*.html)"));

	std::string outFileName = fileName.toLocal8Bit().constData();
	std::string outContent = OutputClass::htmlFile.toLocal8Bit().constData();

	std::ofstream outfile(outFileName);
	outfile << outContent;
	outfile.close();

	qDebug() << "Saved file to " << fileName;
}

void OutputClass::printHTML() {
	QPrinter printer;

	QPrintDialog* printDialog = new QPrintDialog(&printer, this);
	printDialog->setWindowTitle(tr("Print Document"));
	if (printDialog->exec() == QDialog::Accepted) {
		ui.htmlView->print(&printer);
	}
}


OutputClass::~OutputClass()
{
}


