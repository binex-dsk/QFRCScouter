#ifndef BETTERSLIDER_H
#define BETTERSLIDER_H

#include "qslider.h"
#include <QWidget>

namespace Ui {
class BetterSlider;
}

class BetterSlider : public QWidget
{
    Q_OBJECT

public:
    explicit BetterSlider(QWidget *parent = nullptr);
    ~BetterSlider();

    int value();

public slots:
    void setValue(int value);
    void resetSlider();
private:
    Ui::BetterSlider *ui;
};

#endif // BETTERSLIDER_H
