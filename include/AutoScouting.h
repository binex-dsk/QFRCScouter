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
    bool mobility();
    bool neutralZone();
    bool aStop();

private:
    Ui::AutoScouting *ui;
};

#endif // AUTOSCOUTING_H
