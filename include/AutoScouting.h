#ifndef AUTOSCOUTING_H
#define AUTOSCOUTING_H

#include <QWidget>

namespace Ui {
class AutoScouting;
}

class AutoScouting : public QWidget
{
    Q_OBJECT

public:
    explicit AutoScouting(QWidget *parent = nullptr);
    ~AutoScouting();

    void clear();

    int ampPieces();
    int speakerPieces();
    int missedPieces();
    bool mobility();
    bool neutralZone();
    bool aStop();
    bool holding();

private:
    Ui::AutoScouting *ui;
};

#endif // AUTOSCOUTING_H
