#include "OutputClass.h"

const int radius = 10;


OutputClass::OutputClass(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//button connections in the ui
	connect(ui.closeButton, &QPushButton::clicked, this, &OutputClass::closeWindow);
	connect(ui.saveButton, &QPushButton::clicked, this, &OutputClass::saveToFile);

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
	html.replace("PROJECTTITLE", this->projectTitle);

	//html block for each frequency name, rx and tx
	std::string freqValue =
		"<tr> \n"
		"<td width = \"33%\"><H3>FREQNAME</H3></td>\n"
		"<td width = \"33%\"><H3>FREQTX</H3></td>\n"
		"<td width = \"33%\"><H3>FREQRX</H3></td>\n"
		"</tr>\n";
	QString sFreqValue = QString::fromStdString(freqValue);
	int index = html.indexOf("<!--FREQLIST-->");

	//add in each input rx and tx frequency to the html table
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
	
	//find index of category for inserting hit tables
	int orderIndex = html.indexOf("<!--HITCATEGORY-->");
	int orderInter = order;

	//check for double 3rd order calculation if there's 3 or more frequencies
	bool morethanTwo = false;;
	if (rxList.size() > 2) {
		morethanTwo = true;
	}


	int resultIndex = resultList.size()-1;
	//Loop through index vector for each order
	for (int k = orderList.size() - 1; k >= 0; k--) { //vector of indexes for result, loop backwards
		//html block for each order
		QString sOrderBlock =
			"<H2 class=\"topInfo\" style=\"text-align:left\">ORDERTEXT Order EQTEXT Intermodulation: </H2>\n"
			"<table class = \"freqValue\" id = \"tableBG\" width = \"100%\">\n"
			"<tr>\n"
			"<th width = \"10%\"><H2>ID</H2></th>\n"
			"<th width = \"20%\"><H2>IM Freq (MHz)</H2></th>\n"
			"<th width = \"35%\"><H2>Intermodulation Equation</H2></th>\n"
			"<th width = \"35%\"><H2>Freq in Range (MHz)</H2></th>\n"
			"</tr>\n"
			"<!--HITLIST-->\n"
			"</table>\n";

		//find size of order results, and stopping point for looping
		int resultSize = orderList[k];
		int resultStop = resultIndex - resultSize;

		//turn iterating order into Xth text for output order title
		QString o = NumberToOrdinal(orderInter);
		QString sID = QString::number(orderInter);

		QString sEqText = "2 Frequency";
		if (morethanTwo && k == 1) {
			sEqText = "3 Frequency";
		}

		sOrderBlock.replace("ORDERTEXT", o);
		sOrderBlock.replace("EQTEXT", sEqText);
		
		//html block for each equation, freq, range
		QString sResultValue =
			"<tr>\n"
			"<td width = \"10%\"><H3>ID</H3></td>\n"
			"<td width = \"20%\"><H3>FREQ</H3></td>\n"
			"<td width = \"35%\"><H3>EQUATION</H3></td>\n"
			"<td width = \"35%\"><H3>HITS</H3></td>\n"
			"</tr>\n";
		index = sOrderBlock.indexOf("<!--HITLIST-->");
		orderInter = orderInter - 2;

		//repeat three if more than 2 frequencies entered
		if (morethanTwo) {
			if (orderInter < 3) {
				orderInter = 3;
			}
		}

		//add a table line for each product and output for that order
		int counter = resultSize + 1;
		for (int i = resultIndex; i > resultStop; i--) {
			counter--;
			std::string e = eqList[i];
			QString eq = QString::fromStdString(e);

			QString f = QString::number(resultList[i]);
			QString id; 
			if (morethanTwo) {
				if (orderInter == 3 && k == 1) 
					id = sID + "-3-" + QString::number(counter);
				else
					id = sID + "-2-" + QString::number(counter);
			}
			else
				id = sID + "-2-" + QString::number(counter);
			
			//add hits into string list
			QString hits;
			for (int j = 0; j < hitList[i].size(); j++) {
				hits = hits + QString::number(hitList[i][j]);

				//get name of hit frequency
				std::vector<float>::iterator it = std::find(rxList.begin(), rxList.end(), hitList[i][j]);
				int index = std::distance(rxList.begin(), it);

				hits = hits + " [" + nameList[index] + "]";

				if (j < hitList[i].size() - 1){
					hits = hits + ", ";
				}
			}

			QString s = sResultValue;
			s.replace("ID", id);
			s.replace("EQUATION", eq);
			s.replace("FREQ", f);
			s.replace("HITS", hits);

			//insert line into table
			sOrderBlock.insert(index, s);
			resultIndex--;
		}

		//Put no hits found on no hits
		if (resultSize == 0) {
			QString s = sResultValue;
			s.replace("ID", "");
			s.replace("EQUATION", "No Hits Found in range");
			s.replace("FREQ", "");
			s.replace("HITS", "");

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

	QString html;
	html = OutputClass::createOutputHTML(this->resultVector, this->equationVector, this->rxVector, this->txVector, this->nameVector, this->maxOrder, this->calcRange, this->orderVector, this->hitVector);

	//draw graph to base64 and set into html
	QString graph;
	graph = OutputClass::drawGraph(this->resultVector, this->rxVector, this->txVector, this->nameVector, this->orderVector, this->maxOrder);
	QString graph64= "\"data:image/png;base64, " + graph + "\"";
	html.replace("IMAGEBASE64", graph64);

	//set viewer html from created html
	ui.htmlView->setHtml(html);
	OutputClass::htmlFile = html;
}

//draw graph of input frequencies and resulting hit frequencies color coordinated per order
QString OutputClass::drawGraph(std::vector<float> resultList, std::vector<float> rxList, std::vector<float> txList, std::vector<QString> nameList, std::vector<int> orderList, int order) {
	
	QChart* chart = new QChart();
	
	//X axis for the graph
	QValueAxis* axisX = new QValueAxis();
	axisX->setTitleText("Frequency (MHz)");
	axisX->setLabelsBrush(QBrush(Qt::white));
	axisX->setTitleBrush(QBrush(Qt::white));
	chart->addAxis(axisX, Qt::AlignBottom);
	if (!resultList.empty()) {
		auto minMax = std::minmax_element(resultList.begin(), resultList.end());
		float min = minMax.first[0];
		float max = minMax.second[0];
		axisX->setRange(min - (min * 0.001), max + (max * 0.001));
	}
	else {
		axisX->setRange(0,100);
	}
	axisX->setTickCount(10);
	axisX->applyNiceNumbers();

	//y axis for the graph
	QValueAxis* axisY = new QValueAxis();
	axisY->setRange(0, 10.5);
	axisY->setTickType(QValueAxis::TicksDynamic);
	axisY->setTickInterval(1);
	axisY->setLabelsVisible(false);
	//axisY->setTitleText("Amplitude");
	axisY->setLabelsBrush(QBrush(Qt::white));
	axisY->setTitleBrush(QBrush(Qt::white));
	chart->addAxis(axisY, Qt::AlignLeft);

	//draw input rx with name onto graph
	for (int i = 0; i < nameList.size(); i++) {
		QString name = nameList[i];
		float freq = rxList[i];
			
		QLineSeries* series = new QLineSeries();
		name = name;
		series->setName(name);
		*series << QPointF(freq, 0) << QPointF(freq, 10);

		chart->addSeries(series);
		//set graphing line thickness
		QPen pen = series->pen();
		pen.setWidth(10);
		series->setPen(pen);
			
		//attach axis to each series
		series->attachAxis(axisX);
		series->attachAxis(axisY);
	}

	//find if there are more than 2 input frequencies
	bool morethanTwo = false;;
	if (rxList.size() > 2) {
		morethanTwo = true;
	}
	int orderInter = order;

	int resultIndex = resultList.size() - 1;
	//loop through order list vector to find grouping of result order sizes
	for (int k = orderList.size() - 1; k >= 0; k--) {
		
		int resultSize = orderList[k];
		int resultStop = resultIndex - resultSize;
		//one order of graph results
		QString oText = NumberToOrdinal(orderInter);

		//set graphing line thickness
	
		QLineSeries* orderSeries = new QLineSeries();
		QString name = oText;

		if (morethanTwo) {
			if (orderInter == 3 && k == 1)
				name = oText + "-2";
		}

		orderSeries->setName(name);
		chart->addSeries(orderSeries);

		QPen pen = orderSeries->pen();
		orderSeries->setPen(pen);
		QColor orderColor = pen.color();

		for (int i = resultIndex; i > resultStop; i--) {

			float vector = resultList[i];

			QLineSeries* series = new QLineSeries();
			//QString name = oText + "Order";
			//series->setName(name);
			*series << QPointF(vector, 0) << QPointF(vector, 10/orderInter);

			chart->addSeries(series);

			QPen pen = series->pen();
			pen.setWidth(5);
			pen.setColor(orderColor);
			series->setPen(pen);

			//attach axis to each series
			series->attachAxis(axisX);
			series->attachAxis(axisY);

			chart->legend()->markers(series)[0]->setVisible(false);

			resultIndex--;
		}
		//next order
		orderInter = orderInter - 2;

		if (morethanTwo) {
			if (orderInter < 3) {
				orderInter = 3;
			}
		}
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
	chart->layout()->setContentsMargins(0, 0, 0, 0);
	chart->setBackgroundRoundness(0);

	QChartView *chartView = new QChartView(chart);
	chartView->setRenderHint(QPainter::Antialiasing);
	chartView->resize(750, 350);
	
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

	QString defaultName = "IntermodulationOutput_" + this->projectTitle.replace(" ", "_");//add project title to this
	 
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save Intermodulation Output"),
		documents + defaultName,
		tr("Intermod Output Report (*.pdf)"));
	if (QFileInfo(fileName).suffix().isEmpty()) { return; }

	//temporary convert to light theme
	QString tmpHtml = this->htmlFile;
	tmpHtml.replace("color: white", "color: black");
	tmpHtml.replace("background-color: #5a5c5e", "background-color: white");
	tmpHtml.replace("background-color: #282C30", "background-color: #C6C6C6");
	tmpHtml.replace("background-color: #3F464D", "background-color: #ECECEC");
	tmpHtml.replace("width=\'750\'", "width=\'550\'");
	ui.htmlView->setHtml(tmpHtml);

	QPrinter printer(QPrinter::PrinterResolution);
	printer.setOutputFormat(QPrinter::PdfFormat);
	printer.setPaperSize(QPrinter::A4);
	printer.setResolution(600);
	printer.setFullPage(true);
	printer.setOutputFileName(fileName);
	ui.htmlView->print(&printer);
	ui.htmlView->setHtml(this->htmlFile);

	QDesktopServices::openUrl(QUrl(fileName, QUrl::TolerantMode));


	//std::string outFileName = fileName.toLocal8Bit().constData();
	//std::string outContent = OutputClass::htmlFile.toLocal8Bit().constData();

	//std::ofstream outfile(outFileName);
	//outfile << outContent;
	//outfile.close();

	qDebug() << "Saved file to " << fileName;
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
