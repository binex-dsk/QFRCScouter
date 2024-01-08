#ifndef TEAMINFO_H
#define TEAMINFO_H

#include <QWidget>

namespace Ui {
class TeamInfo;
}

class TeamInfo : public QWidget
{
    Q_OBJECT

public:
    explicit TeamInfo(QWidget *parent = nullptr);
    ~TeamInfo();

private:
    Ui::TeamInfo *ui;
};

#endif // TEAMINFO_H
