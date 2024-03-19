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

    int wingPieces();
    int neutralPieces();

    int ampPieces();
    int speakerPieces();

    bool mobility();
    bool aStop();
    bool neutralZone();

private:
    Ui::AutoScouting *ui;
};

#endif // AUTOSCOUTING_H
