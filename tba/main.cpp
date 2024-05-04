#include <QCoreApplication>

#include "MatchData.h"
#include "Match.h"

#include <iostream>

int main(int argc, char *argv[])
{
    MatchData data;

    QStringList tsv;

    for (Match &match : data.schedule().matches()) {
        QStringList line;
        line << QString::number(match.matchNumber());
        line << match.teamForStation(AllianceStation::Blue1);
        line << match.teamForStation(AllianceStation::Blue2);
        line << match.teamForStation(AllianceStation::Blue3);
        line << match.teamForStation(AllianceStation::Red1);
        line << match.teamForStation(AllianceStation::Red2);
        line << match.teamForStation(AllianceStation::Red3);

        tsv << line.join(",");
    }

    std::cout << tsv.join("\n").toStdString() << std::endl;

    return 0;
}
