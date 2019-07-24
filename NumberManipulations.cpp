#include "NumberManipulations.h"

//find the ordinal of a number
QString NumberToOrdinal(int number) {
	QString suffix = "th";
	if (number % 100 < 11 || number % 100 > 13) {
		switch (number % 10) {
		case 1:
			suffix = "st";
			break;
		case 2:
			suffix = "nd";
			break;
		case 3:
			suffix = "rd";
			break;
		}
	}
	return QString::number(number) + suffix;
}