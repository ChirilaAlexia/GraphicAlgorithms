#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_tema2_final.h"
#include <QPaintEvent>
#include "graph.h"

class Maze : public QMainWindow
{
    Q_OBJECT

public:
    Maze(QWidget *parent = nullptr);
    ~Maze();
    virtual void paintEvent(QPaintEvent* e);
private slots:
    void onCheckBoxClicked();
    void onRadioButtonClickedGraf();

private:
    Ui::tema2_finalClass ui;
    Graph* graf;
};
