#ifndef SCALE_H
#define SCALE_H

#include <QWidget>

namespace Ui {
class Scale;
}

class Scale : public QWidget
{
    Q_OBJECT

public:
    explicit Scale(QWidget *parent = nullptr);
    ~Scale();

    int value();

public slots:
    void setValue(int value);

    void reset();
private:
    Ui::Scale *ui;
};

#endif // SCALE_H
