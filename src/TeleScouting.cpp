#include "TeleScouting.h"
#include "ui_TeleScouting.h"

TeleScouting::TeleScouting(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TeleScouting)
{
    ui->setupUi(this);
}

TeleScouting::~TeleScouting()
{
    delete ui;
}

void TeleScouting::clear() {
    ui->ampPieces->setValue(0);
    ui->speakerPieces->setValue(0);
    ui->droppedAmpPieces->setValue(0);
    ui->droppedSpeakerPieces->setValue(0);
    ui->trapPieces->setValue(0);

    ui->spotlights->setValue(0);
    ui->defense->setChecked(false);
    ui->climb->setChecked(false);
}

int TeleScouting::ampPieces() {
    return ui->ampPieces->value();
}

int TeleScouting::speakerPieces() {
    return ui->speakerPieces->value();
}

int TeleScouting::droppedAmpPieces() {
    return ui->droppedAmpPieces->value();
}

int TeleScouting::droppedSpeakerPieces() {
    return ui->droppedSpeakerPieces->value();
}

int TeleScouting::trapPieces() {
    return ui->trapPieces->value();
}

int TeleScouting::spotlights() {
    return ui->spotlights->value();
}

bool TeleScouting::defense() {
    return ui->defense->isChecked();
}

bool TeleScouting::climb() {
    return ui->climb->isChecked();
}
