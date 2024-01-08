#ifndef AUTOSCOUTING_H
#define AUTOSCOUTING_H

#include <QWidget>

namespace Ui {
class Scouting;
}

class Scouting : public QWidget
{
    Q_OBJECT

public:
    explicit Scouting(QWidget *parent = nullptr);
    ~Scouting();

private:
    Ui::Scouting *ui;
};

#endif // AUTOSCOUTING_H
