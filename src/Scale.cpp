#include "Scale.h"
#include "ui_Scale.h"

Scale::Scale(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Scale)
{
    ui->setupUi(this);
}

void Scale::setValue(int value) {
    reset();
}

int Scale::value() {
    // this is cancer
    if (ui->veryBad->isChecked()) {
        return -2;
    }

    if (ui->bad->isChecked()) {
        return -1;
    }

    if (ui->na->isChecked()) {
        return 0;
    }

    if (ui->fine->isChecked()) {
        return 1;
    }

    if (ui->good->isChecked()) {
        return 2;
    }

    if (ui->great->isChecked()) {
        return 3;
    }

    if (ui->elite->isChecked()) {
        return 4;
    }

    return 0;
}

void Scale::reset() {
    ui->na->setChecked(true);
}

Scale::~Scale()
{
    delete ui;
}
