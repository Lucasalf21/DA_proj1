//
// Created by lucasalf on 27-03-2024.
//

#include "City.h"

City::City(std::string name, int id, string code, double demand, int population) {
    this->name = name;
    this->id = id;
    this->code = code;
    this->demand = demand;
    this->population = population;
}

string City::getName() {
    return name;
}

int City::getId() {
    return id;
}

string City::getCode() {
    return code;
}

double City::getDemand() {
    return demand;
}

int City::getPopulation() {
    return population;
}

City::City() {
    this->name = "";
    this->id = -1;
    this->demand = -1;
    this->population = -1;
}
