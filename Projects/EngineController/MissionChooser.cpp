#include "MissionChooser.h"

MissionChooser::MissionChooser(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	moveMission = nullptr;
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