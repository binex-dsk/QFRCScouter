#include "AutoScouting.h"
#include "ui_AutoScouting.h"

Scouting::Scouting(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Scouting)
{
    ui->setupUi(this);
}

Scouting::~Scouting()
{
    delete ui;
}
