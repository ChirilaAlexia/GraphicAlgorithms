#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include <QPainter>
#include "Graph.h" 
#include<QMouseEvent>

class Map : public QWidget {
	Q_OBJECT

public:
	explicit Map(Graph* graph, QWidget* parent = nullptr)
		: QWidget(parent), graph(graph)
	{

	}
	void Resize();

	 void paintEvent(QPaintEvent* event) override;
	 void mousePressEvent(QMouseEvent* event) override;

private:
	Graph* graph;
	int Node1 = -1;
	int Node2 = -1;
	double scaleX, scaleY, offsetX, offsetY;
};

#endif // MAP_H