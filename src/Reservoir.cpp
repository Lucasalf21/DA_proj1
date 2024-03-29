//
// Created by lucasalf on 27-03-2024.
//

#include "Reservoir.h"

Reservoir::Reservoir(std::string name, std::string municipality, int id, std::string code, int maxDelivery) {
    this->name = name;
    this->municipality = municipality;
    this->id = id;
    this->code = code;
    this->maxDelivery = maxDelivery;
}

string Reservoir::getName() {
    return name;
}

string Reservoir::getMunicipality() {
    return municipality;
}

int Reservoir::getId() {
    return id;
}

string Reservoir::getCode() {
    return code;
}

int Reservoir::getMaxDelivery() {
    return maxDelivery;
}

Reservoir::Reservoir() {
    this->name = "";
    this->municipality = "";
    this->id = -1;
    this->code = "";
    this->maxDelivery = -1;
}