#pragma once

#include <QMainWindow>
#include "ui_HCLWidhet.h"

class HCLWidhet : public QMainWindow
{
	Q_OBJECT

public:
	HCLWidhet(QWidget *parent = nullptr);
	~HCLWidhet();

private:
	Ui::HCLWidhetClass ui;
};
