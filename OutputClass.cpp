#include "OutputClass.h"

const int radius = 10;


OutputClass::OutputClass(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//button connections in the ui
	connect(ui.closeButton, &QPushButton::clicked, this, &OutputClass::closeWindow);
	connect(ui.saveButton, &QPushButton::clicked, this, &OutputClass::saveToFile);
	connect(ui.printButton, &QPushButton::clicked, this, &OutputClass::printHTML);
	connect(ui.emailButton, &QPushButton::clicked, this, &OutputClass::sendEmail);

	//rounded  borderless window setup
	this->setWindowFlags(Qt::FramelessWindowHint);
	QPainterPath path = QPainterPath();
	path.addRoundedRect(QRectF(this->rect()), radius, radius);
	QRegion mask = QRegion(path.toFillPolygon().toPolygon());
	this->setMask(mask);
	this->oldPos = this->pos();

}

//accept input of calculation and create the ouput temporary html output
QString OutputClass::createOutputHTML(	std::vector<float> resultList, 
										std::vector<std::string> eqList, 
										std::vector<float> rxList, 
										std::vector<float> txList, 
										std::vector<QString> nameList, 
										int order, 
										float range,
										std::vector<int> orderList, 
										std::vector<std::vector<float>> hitList) {

	//read sample html file for default layout
	std::ifstream infile("default.html");
	std::string content((std::istreambuf_iterator<char>(infile)),
		(std::istreambuf_iterator<char>()));
	QString html = QString::fromStdString(content);

	//get current date
	QDateTime date = QDateTime::currentDateTime();
	QString sDate = date.toString("MMMM dd yyyy");

	//replace in html order, date, and range
	QString sOrder = NumberToOrdinal(order);
	QString sRange = QString::number(range);
	html.replace("ORDER", sOrder);
	html.replace("RANGE", sRange);
	html.replace("DATE", sDate);

	//html block for each frequency name, rx and tx
	std::string freqValue =
		"<tr> \n"
		"<td width = \"33%\"><H3>FREQNAME</H3></td>\n"
		"<td width = \"33%\"><H3>FREQTX</H3></td>\n"
		"<td width = \"33%\"><H3>FREQRX</H3></td>\n"
		"</tr>\n";
	QString sFreqValue = QString::fromStdString(freqValue);
	int index = html.indexOf("<!--FREQLIST-->");
	for (int i = nameList.size() - 1; i >= 0 ; i--) {
		QString name = nameList[i];
		QString rx = QString::number(rxList[i]);
		QString tx = QString::number(txList[i]);

		QString s = sFreqValue;
		s.replace("FREQNAME", name);
		s.replace("FREQRX", rx);
		s.replace("FREQTX", tx);

		html.insert(index, s);
	}
	
	int orderIndex = html.indexOf("<!--HITCATEGORY-->");
	int orderInter = order;

	int resultIndex = 0;
	//Loop through index vector for each order
	for (int k = orderList.size() - 1; k >= 0; k--) { //vector of indexes for result, loop backwards
		//html block for each order
		QString sOrderBlock =
			"<H1 class=\"topInfo\" style=\"text-align:left\">ORDERTEXT Order Intermodulation:</H1>\n"
			"<table class = \"freqValue\" id = \"tableBG\" width = \"100%\">\n"
			"<tr>\n"
			"<th width = \"30%\"><H2>Intermodulation Freq</H2></th>\n"
			"<th width = \"40%\"><H2>Intermodulation Equation</H2></th>\n"
			"<th width = \"30%\"><H2>Hits in Range</H2></th>\n"
			"</tr>\n"
			"<!--HITLIST-->\n"
			"</table>\n";

		//find size of order results, and stopping point for looping
		int resultSize = orderList[k];
		int resultStop = resultIndex + resultSize;

		//turn iterating order into Xth text for output
		QString o = NumberToOrdinal(orderInter);
		sOrderBlock.replace("ORDERTEXT", o);
		
		//html block for each equation, freq, range
		QString sResultValue =
			"<tr>\n"
			"<td width = \"30%\"><H3>FREQ</H3></td>\n"
			"<td width = \"40%\"><H3>EQUATION</H3></td>\n"
			"<td width = \"30%\"><H3>HITS</H3></td>\n"
			"</tr>\n";
		index = sOrderBlock.indexOf("<!--HITLIST-->");
		QString hertz = " MHz";
		orderInter = orderInter - 2;

		//add a table line for each product and output for that order
		for (int i = resultIndex; i < resultStop; i++) {
			std::string e = eqList[i];
			QString eq = QString::fromStdString(e);

			QString f = QString::number(resultList[i]);
			
			//add hits into string list
			QString hits;
			for (int j = 0; j < hitList[i].size(); j++) {
				hits = hits + QString::number(hitList[i][j]) + " ";

				//if (j != hitList[i].size())

			}

			QString s = sResultValue;
			s.replace("EQUATION", eq);
			s.replace("FREQ", f + hertz);
			s.replace("HITS", hits);

			//insert line into table
			sOrderBlock.insert(index, s);
			resultIndex++;
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
	std::vector<std::string> eq = { "2*444 + 1*555 = 777", "1*444 + 2*555 = 888", "1*444 + 2*555 = 888", "1*444 + 2*555 = 888" };
	std::vector<float> rList = { 402.1, 403.2, 402.3, 404.5 };
	std::vector<int> indexR = { 3 };

	QString html;
	html = OutputClass::createOutputHTML(this->resultVector, this->equationVector, this->rxVector, this->txVector, this->nameVector, this->maxOrder, this->calcRange, this->orderVector, this->hitVector);

	//draw graph to base64 and set into html
	QString graph;
	graph = OutputClass::drawGraph(this->resultVector, this->rxVector, this->txVector, this->nameVector);
	QString graph64= "\"data:image/png;base64, " + graph + "\"";
	html.replace("IMAGEBASE64", graph64);

	//set viewer html from created html
	ui.htmlView->setHtml(html);
	OutputClass::htmlFile = html;
}


QString OutputClass::drawGraph(std::vector<float> resultList, std::vector<float> rxList, std::vector<float> txList, std::vector<QString> nameList) {
	
	//TODO method accept result vector, and input vector and loop through them creating graph series
	QChart* chart = new QChart();

	//TODO FIND GRAPH RANGE BASED ON RESULTING FREQUENCIES AS WELL
	//find max of input vectors
	
	//X axis for the graph
	QValueAxis* axisX = new QValueAxis();
	axisX->setTitleText("Frequency (MHz)");
	axisX->setLabelsBrush(QBrush(Qt::white));
	axisX->setTitleBrush(QBrush(Qt::white));
	chart->addAxis(axisX, Qt::AlignBottom);
	if (!rxList.empty()) {
		auto minMax = std::minmax_element(rxList.begin(), rxList.end());
		float min = minMax.first[0];
		float max = minMax.second[0];
		axisX->setRange(min - (min + max) / 2 * 0.05, max + (min + max) / 2 * 0.05);
	}
	else {
		axisX->setRange(0,100);
	}
	axisX->setTickCount(10);
	axisX->applyNiceNumbers();


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

	//draw input rx and tx with name onto graph
	for (int i = 0; i < nameList.size(); i++) {
		QString name = nameList[i];
		float freq = rxList[i];
			
		//determine if rx and tx is the same and draw graph line joined/seperated
		QString ending = " RX";
		if (rxList[i] == txList[i]) {
			ending = " RX/TX";
		}

		QLineSeries* series = new QLineSeries();
		name = name + ending;
		series->setName(name);
		*series << QPointF(freq, 0) << QPointF(freq, 5);

		chart->addSeries(series);
		//set graphing line thickness
		QPen pen = series->pen();
		pen.setWidth(12);
		series->setPen(pen);
			
		//attach axis to each series
		series->attachAxis(axisX);
		series->attachAxis(axisY);
	}
	//TODO DRAW GRAPH AMPLITUDE BASED ON FREQ ORDER
	//draw order series on graph
	/*
	for (int i = 0; i < resultList.size(); i++) {
		double vector = resultList[i];

		QLineSeries* series = new QLineSeries();
		QString name = "Freq " + QString::number(i);
		series->setName(name);
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
	*/

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

//send an email of the output
void OutputClass::sendEmail() {
	//get email address from user
	bool ok;
	std::string email;
	QString e = QInputDialog::getText(this, tr("RF Intermodulation Output"),
		tr("Enter recieving email address:\t\t\t"), QLineEdit::Normal,
		QDir::home().dirName(), &ok);
	if (ok && !e.isEmpty()) {
		qDebug() << e;
		email = e.toStdString();	
	}
	else 
		return;

	QDateTime date = QDateTime::currentDateTime();
	std::string sDate = date.toString("yyyy-MM-dd HH:mm").toStdString();


		
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


void OutputClass::mousePressEvent(QMouseEvent* event) {
	this->oldPos = event->globalPos();
}
void OutputClass::mouseMoveEvent(QMouseEvent* event) {
	QPoint delta = QPoint(event->globalPos() - this->oldPos);
	this->move(this->x() + delta.x(), this->y() + delta.y());
	this->oldPos = event->globalPos();
}


//resizeable borderless window, https://stackoverflow.com/questions/43505580/qt-windows-resizable-frameless-window
bool OutputClass::nativeEvent(const QByteArray& eventType, void* message, long* result)
{
	MSG* msg = static_cast<MSG*>(message);
	if (msg->message == WM_NCHITTEST)
	{
		if (isMaximized())
		{
			return false;
		}

		*result = 0;
		const LONG borderWidth = 8;
		RECT winrect;
		GetWindowRect(reinterpret_cast<HWND>(winId()), &winrect);

		// must be short to correctly work with multiple monitors (negative coordinates)
		short x = msg->lParam & 0x0000FFFF;
		short y = (msg->lParam & 0xFFFF0000) >> 16;

		bool resizeWidth = minimumWidth() != maximumWidth();
		bool resizeHeight = minimumHeight() != maximumHeight();
		if (resizeWidth)
		{
			//left border
			if (x >= winrect.left && x < winrect.left + borderWidth)
			{
				*result = HTLEFT;
			}
			//right border
			if (x < winrect.right && x >= winrect.right - borderWidth)
			{
				*result = HTRIGHT;
			}
		}
		if (resizeHeight)
		{
			//bottom border
			if (y < winrect.bottom && y >= winrect.bottom - borderWidth)
			{
				*result = HTBOTTOM;
			}
			//top border
			if (y >= winrect.top && y < winrect.top + borderWidth)
			{
				*result = HTTOP;
			}
		}
		if (resizeWidth && resizeHeight)
		{
			//bottom left corner
			if (x >= winrect.left && x < winrect.left + borderWidth &&
				y < winrect.bottom && y >= winrect.bottom - borderWidth)
			{
				*result = HTBOTTOMLEFT;
			}
			//bottom right corner
			if (x < winrect.right && x >= winrect.right - borderWidth &&
				y < winrect.bottom && y >= winrect.bottom - borderWidth)
			{
				*result = HTBOTTOMRIGHT;
			}
			//top left corner
			if (x >= winrect.left && x < winrect.left + borderWidth &&
				y >= winrect.top && y < winrect.top + borderWidth)
			{
				*result = HTTOPLEFT;
			}
			//top right corner
			if (x < winrect.right && x >= winrect.right - borderWidth &&
				y >= winrect.top && y < winrect.top + borderWidth)
			{
				*result = HTTOPRIGHT;
			}
		}

		if (*result != 0)
			return true;

		QWidget* action = QApplication::widgetAt(QCursor::pos());
		if (action == this) {
			*result = HTCAPTION;
			return true;
		}
	}
	//set new mask
	QPainterPath path = QPainterPath();
	path.addRoundedRect(QRectF(this->rect()), radius, radius);
	QRegion mask = QRegion(path.toFillPolygon().toPolygon());
	this->setMask(mask);

	return false;
}
