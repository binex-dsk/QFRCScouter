#include "TeamInfo.h"
#include "ui_TeamInfo.h"

#include <QKeyEvent>

TeamInfo::TeamInfo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TeamInfo)
{
    ui->setupUi(this);

    m_buttonMap.insert(AllianceStation::Red1, ui->red1);
    m_buttonMap.insert(AllianceStation::Red2, ui->red2);
    m_buttonMap.insert(AllianceStation::Red3, ui->red3);
    m_buttonMap.insert(AllianceStation::Blue1, ui->blue1);
    m_buttonMap.insert(AllianceStation::Blue2, ui->blue2);
    m_buttonMap.insert(AllianceStation::Blue3, ui->blue3);
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

void TeamInfo::setTeam() {
    int matchNumber = ui->matchNumber->value();
    if (matchNumber == 0) return;

    CompLevel level;
    AllianceStation station;

    if (ui->finals->isChecked()) level = CompLevel::Finals;
    else if (ui->semis->isChecked()) level = CompLevel::Semifinals;
    else level = CompLevel::Quals;

    QMapIterator iter(m_buttonMap);
    while (iter.hasNext()) {
        iter.next();
        if (iter.value()->isChecked()) station = iter.key();
    }

    Match match;
    try {
        match = m_matchData.schedule().getMatch(matchNumber, level);
    } catch (std::exception &e) {
        qDebug() << "Wah wah";
        return;
    }

    QString team = match.teamForStation(station);

    ui->teamNumber->setValue(team.toInt());
}

void TeamInfo::setStation() {
    QString team = ui->teamNumber->text();
    if (team == "0") return;

    int matchNumber = ui->matchNumber->value();
    if (matchNumber == 0) return;

    CompLevel level;

    if (ui->finals->isChecked()) level = CompLevel::Finals;
    else if (ui->semis->isChecked()) level = CompLevel::Semifinals;
    else level = CompLevel::Quals;

    Match match;
    try {
        match = m_matchData.schedule().getMatch(matchNumber, level);
    } catch (std::exception &e) {
        qDebug() << "Okay";
        return;
    }

    AllianceStation station = match.stationForTeam(team);

    if (station == AllianceStation::Invalid) return;
    m_buttonMap.value(station)->setChecked(true);
}

void TeamInfo::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Backspace) {
        qDebug() << "nuhuh";
    }
}
