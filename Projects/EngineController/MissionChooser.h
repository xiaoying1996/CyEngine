#pragma once

#include <QMainWindow>
#include "ui_MissionChooser.h"
#include "MoveMissionWidget.h"

class MissionChooser : public QMainWindow
{
	Q_OBJECT

public:
	MissionChooser(QWidget *parent = nullptr);
	~MissionChooser();

public slots:
	void on_MoveMissionBtn_clicked();

private:
	Ui::MissionChooserClass ui;
	MoveMissionWidget* moveMission;
};
