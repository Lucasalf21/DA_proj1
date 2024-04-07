//
// Created by lucasalf on 27-03-2024.
//

#ifndef PROJ1_2324_MENU_H
#define PROJ1_2324_MENU_H


#include "Data.h"
#include "Graph.h"

class Menu {
private:
    Data* data;
    Graph<string>* g;

public:
    Menu(Data* data, Graph<string>* g);
    void choice1();
    void maximumAmountOfWaterSpecific(set<pair<string, double>> res);
    void maximumAmountOfWaterEach(set<pair<string, double>> res, double total);
    void deficitInEach(set<pair<string, double>> res);

    void choice2();
    void removeReservoir(set<pair<string, double>> originalMaxFlow);
    void removeStation(set<pair<string, double>> originalMaxFlow);
    void removePipe(set<pair<string, double>> originalMaxFlow);
};


#endif //PROJ1_2324_MENU_H
