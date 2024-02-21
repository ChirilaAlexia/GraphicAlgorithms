#include "LuxemburgFinal.h"
#include <QtWidgets/QApplication>
#include "Map.h"
#include "Graph.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Graph* graf=new Graph();
   graf=graf->GraphFromFile("Harta_Luxemburg.xml");
    Map mapa(graf);
    mapa.show();
    return a.exec();
}
