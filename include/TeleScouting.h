#ifndef TELESCOUTING_H
#define TELESCOUTING_H

#include <QWidget>

namespace Ui {
class TeleScouting;
}

class TeleScouting : public QWidget
{
    Q_OBJECT

public:
    explicit TeleScouting(QWidget *parent = nullptr);
    ~TeleScouting();

    void clear();

    int shortAcquire();
    int longAcquire();

    int missedNotes();

    int ampPieces();
    int speakerPieces();
    int shuttled();

    int trapPieces();
    bool defense();
    bool defended();
    bool climb();

private:
    Ui::TeleScouting *ui;
};

#endif // TELESCOUTING_H
