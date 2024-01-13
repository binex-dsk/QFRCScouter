#ifndef SUBJECTIVESCALES_H
#define SUBJECTIVESCALES_H

#include <QWidget>

namespace Ui {
class SubjectiveScales;
}

class SubjectiveScales : public QWidget
{
    Q_OBJECT

public:
    explicit SubjectiveScales(QWidget *parent = nullptr);
    ~SubjectiveScales();

    int driver();
    int defense();
    int speed();
    int tippiness();
    int teamwork();

private:
    Ui::SubjectiveScales *ui;
};

#endif // SUBJECTIVESCALES_H
