#include "BetterSpinBox.h"
#include "ui_BetterSpinBox.h"

BetterSpinBox::BetterSpinBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BetterSpinBox)
{
    ui->setupUi(this);
}

BetterSpinBox::~BetterSpinBox()
{
    delete ui;
}

void BetterSpinBox::setValue(int value) {
    ui->box->setValue(value);
}

int BetterSpinBox::value() {
    return ui->box->value();
}

void BetterSpinBox::setMaximum(int max) {
    ui->box->setMaximum(max);
}

void BetterSpinBox::setWrapping(bool wrap) {
    ui->box->setWrapping(wrap);
}
