#include "BetterSlider.h"
#include "ui_BetterSlider.h"

BetterSlider::BetterSlider(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BetterSlider)
{
    ui->setupUi(this);
}

void BetterSlider::setValue(int value) {
    ui->slider->setValue(value);
}

int BetterSlider::value() {
    return ui->slider->value();
}

void BetterSlider::resetSlider() {
    ui->slider->setValue(ui->spinBox->value());
}
BetterSlider::~BetterSlider()
{
    delete ui;
}
