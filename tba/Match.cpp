#include "Match.h"

#include <QJsonArray>

Match::Match(QJsonObject object) {
    QJsonObject alliances = object.value("alliances").toObject();

    QJsonObject red = alliances.value("red").toObject();
    QJsonArray redTeams = red.value("team_keys").toArray();
    m_teamMap.insert(redTeams.at(0).toString().sliced(3), AllianceStation::Red1);
    m_teamMap.insert(redTeams.at(1).toString().sliced(3), AllianceStation::Red2);
    m_teamMap.insert(redTeams.at(2).toString().sliced(3), AllianceStation::Red3);

    QJsonObject blue = alliances.value("blue").toObject();
    QJsonArray blueTeams = blue.value("team_keys").toArray();
    m_teamMap.insert(blueTeams.at(0).toString().sliced(3), AllianceStation::Blue1);
    m_teamMap.insert(blueTeams.at(1).toString().sliced(3), AllianceStation::Blue2);
    m_teamMap.insert(blueTeams.at(2).toString().sliced(3), AllianceStation::Blue3);

    m_compLevel = CompLevelMap.value(object.value("comp_level").toString());

    if (m_compLevel == CompLevel::Semifinals) {
        m_matchNumber = object.value("set_number").toInt();
    } else {
        m_matchNumber = object.value("match_number").toInt();
    }
}

AllianceStation Match::stationForTeam(const QString &team) {
    return m_teamMap.value(team, AllianceStation::Invalid);
}

QString Match::teamForStation(const AllianceStation &station) {
    return m_teamMap.key(station, "1000");
}

int Match::matchNumber() {
    return m_matchNumber;
}

CompLevel Match::compLevel() {
    return m_compLevel;
}
