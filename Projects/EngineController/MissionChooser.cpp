#include "MissionChooser.h"

MissionChooser::MissionChooser(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	moveMission = nullptr;
	attackMission = nullptr;
}

MissionChooser::~MissionChooser()
{}

void MissionChooser::on_MoveMissionBtn_clicked()
{
	if (moveMission == nullptr)
	{
		moveMission = new MoveMissionWidget();
		moveMission->show();
		moveMission->SetExecuter();
	}
}

void MissionChooser::on_AttackMissionBtn_clicked()
{
	if (attackMission == nullptr)
	{
		attackMission = new AttackMissionWidget();
		attackMission->show();
		attackMission->SetExecuter();
	}
}