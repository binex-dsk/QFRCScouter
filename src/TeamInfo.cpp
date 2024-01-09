#include "TeamInfo.h"
#include "ui_TeamInfo.h"

TeamInfo::TeamInfo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TeamInfo)
{
    ui->setupUi(this);
}

TeamInfo::~TeamInfo()
{
    delete ui;
}

int TeamInfo::teamNumber() {
    return ui->teamNumber->value();
}

int TeamInfo::matchNumber() {
    return ui->matchNumber->value();
}

QString TeamInfo::eventCode() {
    return ui->eventCode->text();
}
