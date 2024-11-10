#include "HCLWidhet.h"

HCLWidhet::HCLWidhet(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromLocal8Bit("ºÏ³ÉÂÃ"));
}

HCLWidhet::~HCLWidhet()
{}
