#include "SubjectiveScales.h"
#include "ui_SubjectiveScales.h"

SubjectiveScales::SubjectiveScales(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SubjectiveScales)
{
    ui->setupUi(this);
}

SubjectiveScales::~SubjectiveScales()
{
    delete ui;
}

void SubjectiveScales::clear() {
    ui->driver->setValue(0);
    ui->defense->setValue(0);
    ui->speed->setValue(0);
}

int SubjectiveScales::driver() {
    return ui->driver->value();
}

int SubjectiveScales::defense() {
    return ui->defense->value();
}

int SubjectiveScales::speed() {
    return ui->speed->value();
}
