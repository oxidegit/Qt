#ifndef LIGHTUI_H
#define LIGHTUI_H

#include <QWidget>

namespace Ui {
    class lightUI;
}

class lightUI : public QWidget
{
    Q_OBJECT

public:
    explicit lightUI(QWidget *parent = 0);
    ~lightUI();

private:
    Ui::lightUI *ui;
};

#endif // LIGHTUI_H
