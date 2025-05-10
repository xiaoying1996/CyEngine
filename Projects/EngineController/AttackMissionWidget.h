#pragma once

#include <QMainWindow>
#include <QMap>
#include <QString>
#include <QTimer>
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
	void on_SendBtn_clicked();//不机动攻击选择的目标下发
	void on_SendBtn_2_clicked();//不机动攻击所有目标下发
	void onHumanComboxSelect(int index);
	void onUavComboxSelect(int index);
	void slot_update();

private:
	Ui::AttackMissionWidgetClass ui;
	std::vector<Model_BasicInfo> models;
	QMap<ModelType, QString > TypeMap;
	string choosedModelName;
	QTimer* timer = nullptr;
};
