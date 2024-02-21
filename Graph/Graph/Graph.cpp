#include "Graph.h"
#include <QMouseEvent>
#include <QGraphicsItem>
#include <QPainter>
#include <QPaintEvent>
#include <QPolygonF>
#include <cmath>

Graph::Graph(QWidget *parent)
    : QMainWindow(parent), isOriented(false),isMoving(false,nullptr)
{
    ui.setupUi(this);
    graf = new Graphic();
    firstNode = new Node();

    connect(ui.radioButton, &QRadioButton::clicked, this, &Graph::onRadioButtonClickedIsOriented);
   connect(ui.checkBox, &QCheckBox::clicked, this, &Graph::onButtonClickedMove);
}

Graph::~Graph()
{
}
void Graph::mouseReleaseEvent(QMouseEvent* e)
{

    if (e->button() == Qt::RightButton)
    {

        if (graf->Collision(e) == nullptr)
        {
            graf->addNode(e->pos());
            update();
            graf->writeToFile("date.out");
        }
        else if (ui.checkBox->isChecked())
        {
            isMoving.first = true;
            isMoving.second = graf->Collision(e);
        }
    }
    else if (e->button() == Qt::LeftButton)
    {
        std::vector<Node*> nodes = graf->getNodes();
        for (Node* n : nodes)
        {

            if (fabs(e->pos().x() - n->getX()) < 10 && fabs(e->pos().y() - n->getY()) < 10)
            {
                if (!firstNode->getSelect())
                {
                    firstNode = n;
                    firstNode->setSelect(true);
                }
                else {
                    if (graf->isMultigraph(firstNode, n) == false)
                    {
                        graf->addArch(firstNode, n);
                        firstNode->setSelect(false);
                    }
                }
                update();
                graf->writeToFile("date.out");
                break;
            }
        }
    }
}
void Graph::paintEvent(QPaintEvent* e)
{
    QPainter p(this);
    std::vector<Node*> noduri = graf->getNodes();
    for (Node* n : noduri)
    {
        if (!n)
            break;

        QRect r(n->getX() - 10, n->getY() - 10, 20, 20);
        p.drawEllipse(r);
        QString s;
        s.setNum(n->getValue());
        p.drawText(r, Qt::AlignCenter, s);
    }
    std::vector<Arch*> arches = graf->getArches();
    if (isOriented)
    {
        for (auto a : arches)
        {
            QPointF startPoint(a->getFirstNode()->getX(), a->getFirstNode()->getY());
            QPointF endPoint(a->getSecondNode()->getX(), a->getSecondNode()->getY());

            // Calculează o versiune mai scurtă a liniei pentru a evita nodurile
            QLineF line(startPoint, endPoint);
            qreal length = line.length();
            qreal nodeRadius = 10.0; // Distanța minimă față de nod

            if (length > 2 * nodeRadius)
            {
                line.setLength(length - nodeRadius); // Eliminăm o distanță minimă

                // Desenăm linia fără a trece peste noduri
                p.drawLine(line);

                // Desenăm săgeata
                qreal arrowHeadSize = 10.0;
                qreal angle = atan2(line.dy(), line.dx());

                int circleRadius = 5;  // sau orice valoare corespunzătoare razei cercului nodului
                qreal x = line.x2() - circleRadius * cos(angle);
                qreal y = line.y2() - circleRadius * sin(angle);

                // Desenează capul săgeții
                p.drawLine(line.p2(), QPointF(x, y));
                p.drawLine(QPointF(x, y), QPointF(x - arrowHeadSize * cos(angle - M_PI / 6),
                    y - arrowHeadSize * sin(angle - M_PI / 6)));
                p.drawLine(QPointF(x, y), QPointF(x - arrowHeadSize * cos(angle + M_PI / 6),
                    y - arrowHeadSize * sin(angle + M_PI / 6)));
            }

        }
        if (firstNode->getValue() >= 0)
        {
            QRect r(firstNode->getX() - 10, firstNode->getY() - 10, 20, 20);
            QPen pen;
            pen.setColor(Qt::red);
            pen.setWidth(2);
            p.setPen(pen);
            p.drawEllipse(r);
            QString s;
            s.setNum(firstNode->getValue());
            p.drawText(r, Qt::AlignCenter, s);
        }

    }
    else
    {
        for (auto a : arches)
        {
            p.drawLine(a->getFirstNode()->getX(), a->getFirstNode()->getY(),
                a->getSecondNode()->getX(), a->getSecondNode()->getY());
        }
        if (firstNode->getValue() >= 0)
        {
            QRect r(firstNode->getX() - 10, firstNode->getY() - 10, 20, 20);
            QPen pen;
            pen.setColor(Qt::yellow);
            pen.setWidth(2);
            p.setPen(pen);
            p.drawEllipse(r);
            QString s;
            s.setNum(firstNode->getValue());
            p.drawText(r, Qt::AlignCenter, s);

        }
    }
}


void Graph::mousePressEvent(QMouseEvent* e)
{
    if (isMoving.first)
    {
        isMoving.second->setCoordinate(e->pos());
       ui.checkBox->setChecked(false);
        isMoving.second = nullptr;
        isMoving.first = false;
        update();
    }
}

void Graph::onButtonClickedMove()
{

}

void Graph::onRadioButtonClickedIsOriented()
{
    isOriented = ui.radioButton->isChecked() ? true : false;
    graf->SetIsOriented(isOriented);

    QPainter painter(this);
    auto arce = graf->getArches();
    for (auto arc : arce)
    {
        if (!arc)
            break;
        painter.drawLine(arc->getFirstNode()->getX(), arc->getFirstNode()->getY(), arc->getSecondNode()->getX(), arc->getSecondNode()->getY());
    }
    update();
}

void Graph::on_checkBox_stateChanged(int arg1)
{

}

