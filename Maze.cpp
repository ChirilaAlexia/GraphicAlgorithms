#include "Maze.h"
#include "qline.h"
#include <QLine>

Maze::Maze(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
	graf = new Graph();
	graf->ReadFromFile("date.in");
	graf->GrafFromMatrix();

	connect(ui.checkBox, &QCheckBox::clicked, this, &Maze::onCheckBoxClicked);
	graf->setWayOut(false);
	connect(ui.radioButton, &QRadioButton::clicked, this, &Maze::onRadioButtonClickedGraf);
}

void Maze::onCheckBoxClicked()
{
	graf->setWayOut(ui.checkBox->isChecked() ? true : false);
}
Maze::~Maze()
{
	delete graf;
}
void Maze::paintEvent(QPaintEvent* e)
{

	if (graf->getWayOut() == false)
	{
		if (graf->getPrintGraf() == false)
		{
			QPainter painter(this);
			std::vector<std::vector<int>>mat = graf->getFileMatrix();
			for (int i = 0; i < mat.size(); i++)
			{
				for (int j = 0; j < mat[i].size(); j++)
				{
					if (graf->FindNodeFromPozition({ i,j })->getColour() == "black")
					{
						painter.setBrush(Qt::black);
						painter.drawRect(j * 40, i * 40, 40, 40);
					}
					else if (graf->FindNodeFromPozition({ i,j })->getColour() == "red")
					{
						painter.setBrush(Qt::red);
						painter.drawRect(j * 40, i * 40, 40, 40);
					}
					else if (graf->FindNodeFromPozition({ i,j })->getColour() == "blue")
					{
						painter.setBrush(Qt::blue);
						painter.drawRect(j * 40, i * 40, 40, 40);
					}
					else
					{
						painter.setBrush(Qt::yellow);
						painter.drawRect(j * 40, i * 40, 40, 40);
					}
				}

			}
			update();
		}
		else
		{
			QPainter p(this);
			for (auto x : graf->getNodesGraf())
			{
				if (!x)
					break;
				std::pair<int, int> aux = x->getMatrixPozition();
				std::string col = x->getColour();
				if (col == "red")
					p.setBrush(Qt::red);
				else if (col == "blue")
					p.setBrush(Qt::blue);
				else
					p.setBrush(Qt::yellow);
				QRect r(x->getCoordinate().x() - 10, x->getCoordinate().y() - 10, 20, 20);
				p.drawEllipse(r);
				update();
			}

			for (auto a : graf->getArches())
			{
				if (a->getFirstNode()->getMatrixPozition() != a->getSecondNode()->getMatrixPozition())
				{
					if (a->getFirstNode()->getCoordinate().y() == a->getSecondNode()->getCoordinate().y() + 40 && a->getFirstNode()->getCoordinate().x() == a->getSecondNode()->getCoordinate().x())
					{
						p.setPen(QPen(Qt::black));
						int x1 = a->getFirstNode()->getCoordinate().x();
						int x2 = a->getSecondNode()->getCoordinate().x();
						int y1 = a->getFirstNode()->getCoordinate().y() - 10;
						int y2 = a->getSecondNode()->getCoordinate().y() + 10;
						QPoint x(x1, y1);
						QPoint y(x2, y2);
						p.drawLine(x, y);
						update();

					}
					if (a->getFirstNode()->getCoordinate().y() == a->getSecondNode()->getCoordinate().y() && a->getFirstNode()->getCoordinate().x() == a->getSecondNode()->getCoordinate().x() + 40)
					{
						p.setPen(QPen(Qt::black));
						int x1 = a->getFirstNode()->getCoordinate().x() - 10;
						int x2 = a->getSecondNode()->getCoordinate().x() + 10;
						int y1 = a->getFirstNode()->getCoordinate().y();
						int y2 = a->getSecondNode()->getCoordinate().y();
						QPoint x(x1, y1);
						QPoint y(x2, y2);
						p.drawLine(x, y);
						update();

					}
				}
			}

		}

	}
	else
	{
		if (graf->getPrintGraf() == false)
		{
			QPainter p(this);
			graf->FindPathOut(graf->getStart());
			std::vector<std::vector<int>>mat = graf->getFileMatrix();
			for (auto n : graf->getNodes())
			{
				int i = n->getMatrixPozition().first;
				int j = n->getMatrixPozition().second;
				if (n->getColour() == "black")
				{
					p.setBrush(Qt::black);
				}
				else if (n->getColour() == "red")
				{
					p.setBrush(Qt::red);
				}
				else if (n->getColour() == "blue")
				{
					p.setBrush(Qt::blue);
				}
				else if (n->getColour() == "green")
				{
					p.setBrush(Qt::green);
				}
				else
					p.setBrush(Qt::yellow);

				p.drawRect(j * 40, i * 40, 40, 40);
				update();
			}
		}
		else
		{
			QPainter p(this);
			for (auto x : graf->getNodesGraf())
			{
				if (!x)
					break;
				std::pair<int, int> aux = x->getMatrixPozition();
				std::string col = x->getColour();
				if (col == "red")
					p.setBrush(Qt::red);
				else if (col == "blue")
					p.setBrush(Qt::blue);
				else if (col == "green")
					p.setBrush(Qt::green);
				else
					p.setBrush(Qt::yellow);
				QRect r(x->getCoordinate().x() - 10, x->getCoordinate().y() - 10, 20, 20);
				p.drawEllipse(r);
				update();
			}

			for (auto a : graf->getArches())
			{
				if (a->getFirstNode()->getMatrixPozition() != a->getSecondNode()->getMatrixPozition())
				{
					if (a->getFirstNode()->getCoordinate().y() == a->getSecondNode()->getCoordinate().y() + 40 && a->getFirstNode()->getCoordinate().x() == a->getSecondNode()->getCoordinate().x())
					{
						p.setPen(QPen(Qt::black));
						int x1 = a->getFirstNode()->getCoordinate().x();
						int x2 = a->getSecondNode()->getCoordinate().x();
						int y1 = a->getFirstNode()->getCoordinate().y() - 10;
						int y2 = a->getSecondNode()->getCoordinate().y() + 10;
						QPoint x(x1, y1);
						QPoint y(x2, y2);
						p.drawLine(x, y);
						update();

					}
					if (a->getFirstNode()->getCoordinate().y() == a->getSecondNode()->getCoordinate().y() && a->getFirstNode()->getCoordinate().x() == a->getSecondNode()->getCoordinate().x() + 40)
					{
						p.setPen(QPen(Qt::black));
						int x1 = a->getFirstNode()->getCoordinate().x() - 10;
						int x2 = a->getSecondNode()->getCoordinate().x() + 10;
						int y1 = a->getFirstNode()->getCoordinate().y();
						int y2 = a->getSecondNode()->getCoordinate().y();
						QPoint x(x1, y1);
						QPoint y(x2, y2);
						p.drawLine(x, y);
						update();

					}
				}
			}

		}

	}



}

void Maze::onRadioButtonClickedGraf()
{
	graf->setPrintGraf(ui.radioButton->isChecked() ? true : false);
}
