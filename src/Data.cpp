//
// Created by lucasalf on 28-03-2024.
//

#include "Data.h"

Data::Data() {}

void Data::newCity(City *city, string code) {
    cities[code] = city;
}

void Data::newPipe(Pipe *pipe) {
    pipes.insert(pipe);
}

void Data::newReservoir(Reservoir *reservoir, string code) {
    reservoirs[code] = reservoir;
}

void Data::newStation(Station *station, string code) {
    stations[code] = station;
}

map<string, City *> Data::getCities() {
    return cities;
}

set<Pipe *> Data::getPipes() {
    return pipes;
}

map<string, Reservoir *> Data::getReservoirs() {
    return reservoirs;
}

map<string, Station *> Data::getStations() {
    return stations;
}

City* Data::findCity(string code) {
    return cities[code];
}

Reservoir* Data::findReservoir(string code) {
    return reservoirs[code];
}