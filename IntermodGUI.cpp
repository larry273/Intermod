#include "IntermodGUI.h"


using namespace std;

const int radius = 10;



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

	//borderless rounded window setup
	this->setWindowFlags(Qt::FramelessWindowHint);
	QPainterPath path = QPainterPath();
	path.addRoundedRect(QRectF(this->rect()), radius, radius);
	QRegion mask = QRegion(path.toFillPolygon().toPolygon());
	this->setMask(mask);
	this->oldPos = this->pos();

	//connect button push to calculate intermod
	connect(ui.calculateButton, &QPushButton::clicked, this, &Intermod::getIntermodValues);
	connect(ui.clearButton, &QPushButton::clicked, this, [this]() {Intermod::clearValues(true);});
	connect(ui.helpButton, &QPushButton::clicked, this, &Intermod::showHelp);

	connect(ui.closeButton, &QPushButton::clicked, this, &Intermod::closeWindow);
	connect(ui.maxButton, &QPushButton::clicked, this, &Intermod::maximizeWindow);
	connect(ui.minButton, &QPushButton::clicked, this, &Intermod::minimizeWindow);

	//set icons for max,min,close
	QByteArray  maxIcon = "iVBORw0KGgoAAAANSUhEUgAAAIAAAACACAYAAADDPmHLAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsAAAA7AAWrWiQkAAAP5SURBVHhe7ZxNSxVRAIY1qChDqChLolq06C9otojKkKBt/ZGIyBQqjKhNq35CQXsjpAT7zgrDpIigXZSRSUmmlfa+94xlMvc2C9Fz5n0feDhnps31znPnQ7unvru7uw5shedgB2yCK2AsfIL3YRcc4o4EaIY98BDk+1kPY2EU9sNO+IYB8AU+htthzEzC/fBBZSteNsFBuKOyFS+fYQs/6fxkxX7wyRp4KUyj5gSM/eCT9fA8AzhQ2UyDFtgQptHC034qtDOAxjBPhpiup3msysYUaIjpZq8Iz+BEmEZL7Pco/5BSAD/g8TCNGt79j4dp/KQQwE94D/JehY8vsfMatsFe+J07YqZIAPwdAa+7y+VKyDd0AKbCCDwM+eSS9zMtpTVJ7R7ALDIOQBwGkNJji1lkGIDPAsL44ItTJAA+f5uSUiSAX9loSogvAeI4AHEcgDgOQBwHII4DEMcBaDPlALSZdQDlZnU2VoUBOILyUug/hPjPwcIU+fRPZ6MpIUUCmMlGU0J8/RfHAYjjAMRxAOI4AHEcgDgOQBwHII4DEMcBiOMAxGEAU2GaC/8t+kUOTFX4ra5af8v5ygDuhnkuD7PRpAm/1fUkTHMZZAAnYd7CS6zndJiahOGKoHlnAZ7duxjAMGyFXNOGq3FyTR6eFbgq5x1o0qYPHoGvKlsBLrnbDp/OrRVsNOAytrwsjFW2gJ8CtPgI/xx84gDEcQDiOABxHIA4DkAcByCOAxDHAYjjAMRxAOI4AHEcgDgOQBwHII4DEMcBiOMAxHEA4jgAcRyAOA5AHAcgjgMQxwGI4wDEcQDiOABxHIA4DkAcByCOAxDHAYjjAMRxAOI4AHEcgDgOQBwHIM5cALvgVfgBjsLrcDc05WAbvAJfwOfwMtwC67hQJA/+I7iBO+bxBXIF0ZHKlkmVnZBrPjdVtv7yDrbyDNADFx580ggvhKlJGB7fhQefNMOLDIBrAldjXzaadDmYjXl0MIC8T/8ca7PRpMvGbMxjnZ8Cyk99NubiAMRxAOI4AHEcgDgOQBwHII4DEMcBiOMAxHEA4jgAcRyAOA5AHAcgjgMQxwGI4wDEcQDiOABxHIA4DkAcByCOAxDHAYjjAMRxAOI4AHEcgDgOQBwHIE6RAGaX0Rn4Hl6DXMomFeavuZT3cy2lNYn9DMDvtnN5k6OQ6xilEMHcmkvH4GbuiJmULgFcyeRMmEZNtTWXoiS1e4C2bIyZWmsuRQcDGA/TJPjvNS0CUvpQTfLF3g7zJLiVjTEzkI0p0M8AOiEXhYydMXg2TKOG7+dEmEbNN3iKAbyEXBH0BpyCscHX1Av3wLfcETnDcC/sg9PcERl8TTch7qfqhn4D3Ea1m9qyCGgAAAAASUVORK5CYII=";
	QByteArray  closeIcon = "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";
	QByteArray  minIcon = "iVBORw0KGgoAAAANSUhEUgAAAIAAAAAKCAYAAAB8FVZ1AAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAAC4cAAAuHAZNAh1MAAAC1SURBVFhH7dg9DgFBGIfxoRBC4gziCBKVA6BwAXECcYY5hESrUAmJrFqt16lVIlH4qPH8syTOMO/7JL/N7LTzZpPZQowxfGthiAGq2vCS64EN5jhq4zcAOvQlynrxku+GPvZFHm2s4Idvpzp2aGoARijBs1UFEw2APv+ezboagHe+9gz20gCs87VnsK0GYAFdDzxbXTHTABzQwxOejS7o4PT/I6iBMXQ/rGnDS647MkxxDiGED9ErHVmf84uqAAAAAElFTkSuQmCC";

	std::vector<QByteArray> icons = { closeIcon, minIcon, maxIcon };
	std::vector<QPushButton *> buttons = { ui.closeButton, ui.minButton, ui.maxButton };

	QPixmap image;
	QIcon icon;
	for (int i = 0; i < buttons.size(); i++) {
		image.loadFromData(QByteArray::fromBase64(icons[i]));
		icon = image;
		buttons[i]->setIcon(icon);
	}

	//populate order dropdown with number ordinals
	ui.orderBox->clear();
	QString oText;
	QString o;
	QString orderTh = "th";
	for (int i = 0; i < 112; i++) {
		i = i + 1;
		o = NumberToOrdinal(i);
	
		oText = " Order";
		oText = o + oText;
		ui.orderBox->addItem(oText);
	}
	ui.orderBox->setCurrentIndex(2);

}

//Window max, min, and close buttons
void Intermod::minimizeWindow() {
	this->showMinimized();
}
void Intermod::maximizeWindow() {
	if (this->isMaximized()) {
		this->setWindowState(Qt::WindowNoState);
	}
	else {
		this->showMaximized();
	}
}
void Intermod::closeWindow() {
	QCoreApplication::quit();
}

//get the values for intermod calculation from the interface
void Intermod::getIntermodValues() {
	qDebug() << "-- Intermod calculation values from interface -- ";
	//regular expressions for checking input
	QRegExp re("[0-9]*\\.?[0-9]"); //digits regular expression with decimal
	QRegExp nameRe("^[a-zA-Z0-9,. _-]{1,20}$"); //vector name regex

	//Get range and order from interface
	QString freqString = ui.searchLine->text();
	if (!re.exactMatch(freqString)) {
		Intermod::messageIndicate("Frequency range must be a valid number");
		return;
	}
	float freqRange = ui.searchLine->text().toFloat();
	QString orderText = ui.orderBox->currentText();
	if (orderText.length() > 10) {
		orderText = orderText.left(3);
	}
	else if (orderText.length() > 9) {
		orderText = orderText.left(2);
	}
	else {
		orderText = orderText.left(1);
	}
	int order = orderText.toInt();
	qDebug() << "Max Order: " << order << "Frequency Range: " << freqRange;

	//tx and rx input vectors
	vector<QString> nameVector;
	vector<float> txVector;
	vector<float> rxVector;

	QString name;
	QString sRxFreq;
	QString sTxFreq;

	bool inputRow = false;
	vector<int> inputCheck = { 0,0,0 };

	//iterate through table to get rx and tx frequences and names associated 
	for (int row = 0; row < ui.tableWidget->rowCount(); row++) {
		//check each row for if not blank or
		for (int column = 0; column < ui.tableWidget->columnCount(); column++) {
			QTableWidgetItem* item(ui.tableWidget->item(row, column));
			if (item && !(ui.tableWidget->item(row, column)->text() == "")) {
				QString t = ui.tableWidget->item(row, column)->text();
				t = t.simplified();
				if (t != "") {
					qDebug() << "Cell has contents";
					inputCheck[column] = 1;
					inputRow = true;
				}
			}
		}

		//check if a value is missing in the row
		if (inputRow) {
			//if a zero exists in the input check vector it has a blank input
			vector<int>::iterator it = std::find(inputCheck.begin(), inputCheck.end(), 0);
			if (it != inputCheck.end()) {
				int index = distance(inputCheck.begin(), it);
				if (index == 0) {
					Intermod::messageIndicate("Please enter a name for each frequency");
					return;
				}
				else if (index == 1 || index == 2) {
					Intermod::messageIndicate("Please enter a value for each frequency");
					return;
				}
			}
		}
		
		//parse values from table into ouput vectors
		for (int column = 0; column < ui.tableWidget->columnCount(); column++) {
			if (inputRow) {
				if (column == 0) {
					qDebug() << "Name: " << ui.tableWidget->item(row, column)->text();
					name = ui.tableWidget->item(row, column)->text();
					//Check input against regular expression
					if (!nameRe.exactMatch(name)) {
						Intermod::messageIndicate("Please enter a valid name for each frequency");
						return;
					}
					nameVector.push_back(name);
				}
				else if (column == 1) {
					qDebug() << "Tx Freq: " << ui.tableWidget->item(row, column)->text();
					sTxFreq = ui.tableWidget->item(row, column)->text();
					//Check input against regular expression
					if (!re.exactMatch(sTxFreq)) {
						Intermod::messageIndicate("Frequency values must be a valid number");
						return;
					}
					float txFreq = sTxFreq.toFloat();
					txVector.push_back(txFreq);
				}
				else if (column == 2) {
					qDebug() << "Rx Freq: " << ui.tableWidget->item(row, column)->text();
					sRxFreq = ui.tableWidget->item(row, column)->text();
					//Check input against regular expression
					if (!re.exactMatch(sRxFreq)) {
						Intermod::messageIndicate("Frequency values must be a valid number");
						return;
					}
					float rxFreq = sRxFreq.toFloat();
					rxVector.push_back(rxFreq);
				}
			}
		}
		//reset input check
		inputCheck = { 0,0,0 };
		inputRow = false;
	}

	//set output members to input names, frequencies, order and range
	output->txVector = txVector;
	output->rxVector = rxVector;

	output->nVector = nameVector;
	output->maxOrder = order;
	output->calcRange = freqRange;

	//run calculation and show output
	//calculate stuff here

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
	ui.tableWidget->setRowCount(8);
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
		output->setHTML();
	}
}


void Intermod::mousePressEvent(QMouseEvent* event) {
	if (!this->isMaximized() && !(ui.orderBox->geometry().contains(event->pos()))) {
		this->oldPos = event->globalPos();
	}
}
void Intermod::mouseMoveEvent(QMouseEvent* event) {
	if (!this->isMaximized() && !(ui.orderBox->geometry().contains(event->pos()))) {
		QPoint delta = QPoint(event->globalPos() - this->oldPos);
		this->move(this->x() + delta.x(), this->y() + delta.y());
		this->oldPos = event->globalPos();
	}	
}


//resizeable borderless window, https://stackoverflow.com/questions/43505580/qt-windows-resizable-frameless-window
bool Intermod::nativeEvent(const QByteArray& eventType, void* message, long* result)
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

