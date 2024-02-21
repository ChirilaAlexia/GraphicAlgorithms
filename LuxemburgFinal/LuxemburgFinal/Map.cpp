#include "Map.h"
#include<algorithm>

void Map::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    if (!graph) return;
    Resize(); 

    for (auto pair : graph->GetVec()) {
        for (auto arch : pair.second) {
            Node* fromNode = graph->GetNodes().at(arch->GetFrom());
            Node* toNode = graph->GetNodes().at(arch->GetTo());

            int fromX = (fromNode->x() - offsetX) * scaleX;
            int fromY = (fromNode->y() - offsetY) * scaleY;
            int toX = (toNode->x() - offsetX) * scaleX;
            int toY = (toNode->y() - offsetY) * scaleY;

            painter.drawLine(fromX, fromY, toX, toY);
        }
    }
    if (Node1 != -1 && Node2 != -1) {
        std::vector<int> path = graph->DijkstraQueue(Node1, Node2);
        painter.setPen(QPen(Qt::green, 2)); 

        for (size_t i = 0; i < path.size() - 1; i++) {
            Node* fromNode = graph->GetNodes().at(path[i]);
            Node* toNode = graph->GetNodes().at(path[i + 1]);

            int fromX = (fromNode->x() - offsetX) * scaleX;
            int fromY = (fromNode->y() - offsetY) * scaleY;
            int toX = (toNode->x() - offsetX) * scaleX;
            int toY = (toNode->y() - offsetY) * scaleY;

            painter.drawLine(fromX, fromY, toX, toY);
        }
    }
    if (Node1 != -1) {
        Node* selectedNode = graph->GetNodes().at(Node1);
        int x = (selectedNode->x() - offsetX) * scaleX;
        int y = (selectedNode->y() - offsetY) * scaleY;

        painter.setBrush(Qt::green);
        painter.drawEllipse(x, y, 5, 5); 
    }
}

void Map::Resize() {
    double minX = std::numeric_limits<double>::max();
    double maxX = std::numeric_limits<double>::lowest();
    double minY = std::numeric_limits<double>::max();
    double maxY = std::numeric_limits<double>::lowest();

    for (auto pair : graph->GetNodes()) {
        Node* node = pair.second;
        minX = std::min(minX, node->x());
        maxX = std::max(maxX, node->x());
        minY = std::min(minY, node->y());
        maxY = std::max(maxY, node->y());
    }

    scaleX = width() / (maxX - minX);
    scaleY = -height() / (maxY - minY);
    offsetX = minX;
    offsetY = maxY;
}

void Map::mousePressEvent(QMouseEvent* event) {
    int mouseX = event->pos().x();
    int mouseY = event->pos().y();
    Resize();

    double clickedX = (mouseX / scaleX) + offsetX;
    double clickedY = (mouseY / scaleY) + offsetY;

    int closestNode = -1;
    double minDistance = std::numeric_limits<double>::max();

   
    for (auto pair : graph->GetNodes()) {
        Node* node = pair.second;
        double distance = sqrt(pow(node->x() - clickedX, 2) + pow(node->y() - clickedY, 2));

        if (distance < minDistance) {
            minDistance = distance;
            closestNode = pair.first;
        }
    }

    if (Node1 != -1 && Node2 != -1) {
        Node1 = closestNode;
        Node2 = -1;
    }
    else if (Node1 == -1)
        Node1 = closestNode;

    else
        Node2 = closestNode;


    update();
}

