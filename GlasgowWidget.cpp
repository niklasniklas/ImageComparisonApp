#include "GlasgowWidget.h"



GlasgowWidget::GlasgowWidget(QWidget *parent)
	: ComparisonWidget_generic(parent)
{
	_difficulty = 1;
}


GlasgowWidget::~GlasgowWidget()
{
}

void GlasgowWidget::widgetClicked(int no)
{
	int a = 0;
}

void GlasgowWidget::setDifficulty(int no)
{
	_difficulty = no;
}
