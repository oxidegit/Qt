#ifndef EQUIPMENTUI_H
#define EQUIPMENTUI_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>   // Íø×´

namespace Ui {
    class equipmentUI;
}

class equipmentUI : public QWidget
{
    Q_OBJECT

public:
    explicit equipmentUI(QWidget *parent = 0);
    ~equipmentUI();

private:
    Ui::equipmentUI *ui;

    int e_TV;
    int e_JBL;
};

#endif // EQUIPMENTUI_H
