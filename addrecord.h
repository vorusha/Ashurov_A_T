#ifndef ADDRECORD_H
#define ADDRECORD_H

#include <QWidget>

namespace Ui {
class addrecord;
}

class addrecord : public QWidget
{
    Q_OBJECT

public:
    explicit addrecord(QWidget *parent = nullptr);
    ~addrecord();

private:
    Ui::addrecord *ui;
};

#endif // ADDRECORD_H
