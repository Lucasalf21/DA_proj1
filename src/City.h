//
// Created by lucasalf on 27-03-2024.
//

#ifndef PROJ1_2324_CITY_H
#define PROJ1_2324_CITY_H

#include <string>

using namespace std;

class City {
private:
    string name;
    int id;
    string code;
    double demand;
    int population;

public:
    City();
    City(string name, int id, string code, double demand, int population);
    string getName();
    int getId();
    string getCode();
    double getDemand();
    int getPopulation();
};


#endif //PROJ1_2324_CITY_H
