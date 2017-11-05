#include "GlasgowTest.h"
#include <qstandardpaths.h>


GlasgowTest::GlasgowTest(int no)
{
	_no_of_comparisons = no;

	QString str1 = QStandardPaths::writableLocation(QStandardPaths::StandardLocation::DesktopLocation);
	QString str2 = QStandardPaths::writableLocation(QStandardPaths::StandardLocation::DocumentsLocation);
	QString str3 = QStandardPaths::writableLocation(QStandardPaths::StandardLocation::PicturesLocation);
}


GlasgowTest::~GlasgowTest()
{
}

void GlasgowTest::nextItem(void)
{
}

bool GlasgowTest::isCorrect(bool answer)
{
	return false;
}

