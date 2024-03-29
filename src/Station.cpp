//
// Created by lucasalf on 27-03-2024.
//

#include "Station.h"

Station::Station(int id, std::string code) {
    this->id = id;
    this->code = code;
}

int Station::getId() {
    return id;
}

string Station::getCode() {
    return code;
}

Station::Station() {
    this->id = -1;
    this->code = "";
}