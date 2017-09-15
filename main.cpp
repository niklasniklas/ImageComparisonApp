#include "imagecomparisonapp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ImageComparisonApp w;
	w.show();
	return a.exec();
}
