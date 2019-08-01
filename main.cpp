#include "IntermodGUI.h"
#include "CalculationTerminal.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	Intermod w;
	w.show();
	return a.exec();
}
