//
// Created by lucasalf on 28-03-2024.
//

#include "Data.h"

Data::Data() {}

void Data::newCity(City *city) {
    cities.insert(city);
}

void Data::newPipe(Pipe *pipe) {
    pipes.insert(pipe);
}

void Data::newReservoir(Reservoir *reservoir) {
    reservoirs.insert(reservoir);
}

void Data::newStation(Station *station) {
    stations.insert(station);
}

set<City *> Data::getCities() {
    return cities;
}

set<Pipe *> Data::getPipes() {
    return pipes;
}

set<Reservoir *> Data::getReservoirs() {
    return reservoirs;
}

set<Station *> Data::getStations() {
    return stations;
}