#pragma once

#include <QtWidgets/QMainWindow>
#include "qradiobutton.h"
#include "graphic.h"
#include "ui_Graph.h"

class Graph : public QMainWindow
{
    Q_OBJECT

public:
    Graph(QWidget *parent = nullptr);
    ~Graph();

    virtual void mouseReleaseEvent(QMouseEvent* e);
    virtual void paintEvent(QPaintEvent* e);
    virtual void mousePressEvent(QMouseEvent* e);

private slots:
    void onRadioButtonClickedIsOriented();
    void onButtonClickedMove();
    void on_checkBox_stateChanged(int arg1);

private:
    Ui::GraphClass ui;
    Node* firstNode;
    Graphic* graf;
    bool isOriented;
    std::pair<bool, Node*>isMoving;
};

