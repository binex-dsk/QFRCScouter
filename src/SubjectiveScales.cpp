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

int SubjectiveScales::driver() {
    return ui->driver->value();
}

int SubjectiveScales::defense() {
    return ui->defense->value();
}

int SubjectiveScales::speed() {
    return ui->speed->value();
}

int SubjectiveScales::tippiness() {
    return ui->tippiness->value();
}

int SubjectiveScales::teamwork() {
    return ui->teamwork->value();
}
