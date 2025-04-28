#pragma once

#include <QMainWindow>
#include "ui_MissionChooser.h"
#include "MoveMissionWidget.h"
#include "AttackMissionWidget.h"

class MissionChooser : public QMainWindow
{
	Q_OBJECT

public:
	MissionChooser(QWidget *parent = nullptr);
	~MissionChooser();

public slots:
	void on_MoveMissionBtn_clicked();
	void on_AttackMissionBtn_clicked();

private:
	Ui::MissionChooserClass ui;
	MoveMissionWidget* moveMission;
	AttackMissionWidget* attackMission;
};
