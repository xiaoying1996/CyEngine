#pragma once

#include <QMainWindow>
#include <QMap>
#include <QString>
#include "ui_AttackMissionWidget.h"
#include "../src/Public/PublicStruct.h"
#include "../src/Public/PublicEnum.h"

class AttackMissionWidget : public QMainWindow
{
	Q_OBJECT

public:
	AttackMissionWidget(QWidget *parent = nullptr);
	~AttackMissionWidget();
	void SetExecuter();

public slots:
	void on_SendBtn_clicked();
	void onHumanComboxSelect(int index);
	void onUavComboxSelect(int index);

private:
	Ui::AttackMissionWidgetClass ui;
	std::vector<Model_BasicInfo> models;
	QMap<ModelType, QString > TypeMap;
	string choosedModelName;
};
