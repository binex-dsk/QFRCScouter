#include "AutoScouting.h"
#include "ui_AutoScouting.h"

AutoScouting::AutoScouting(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AutoScouting)
{
    ui->setupUi(this);
}

AutoScouting::~AutoScouting()
{
    delete ui;
}

void AutoScouting::clear() {
    ui->ampPieces->setValue(0);
    ui->speakerPieces->setValue(0);
    ui->mobility->setChecked(false);
    ui->neutral->setChecked(false);
    ui->stopped->setChecked(false);
}

int AutoScouting::ampPieces() {
    return ui->ampPieces->value();
}

int AutoScouting::speakerPieces() {
    return ui->speakerPieces->value();
}

bool AutoScouting::mobility() {
    return ui->mobility->isChecked();
}

bool AutoScouting::neutralZone() {
    return ui->neutral->isChecked();
}

bool AutoScouting::aStop() {
    return ui->stopped->isChecked();
}
