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

    ui->wing->setValue(0.);
    ui->neutral->setValue(0.);

    ui->neutralZone->setChecked(false);
    ui->mobility->setChecked(false);
    ui->stopped->setChecked(false);
}

int AutoScouting::wingPieces() {
    return ui->wing->value();
}

int AutoScouting::neutralPieces() {
    return ui->neutral->value();
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

bool AutoScouting::aStop() {
    return ui->stopped->isChecked();
}

bool AutoScouting::neutralZone() {
    return ui->neutralZone->isChecked();
}
