#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_LuxemburgFinal.h"

class LuxemburgFinal : public QMainWindow
{
    Q_OBJECT

public:
    LuxemburgFinal(QWidget *parent = nullptr);
    ~LuxemburgFinal();

private:
    Ui::LuxemburgFinalClass ui;
};
