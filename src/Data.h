//
// Created by lucasalf on 28-03-2024.
//

#ifndef PROJ1_2324_DATA_H
#define PROJ1_2324_DATA_H

#include "City.h"
#include "Pipe.h"
#include "Reservoir.h"
#include "Station.h"
#include <map>
#include <set>

using namespace std;

class Data {
private:
    map<string, City*> cities = {};
    set<Pipe*> pipes = {};
    map<string, Reservoir*> reservoirs = {};
    map<string, Station*> stations = {};

public:
    Data();
    void newCity(City *city, string code);
    void newPipe(Pipe *pipe);
    void newReservoir(Reservoir *reservoir, string code);
    void newStation(Station *station, string code);
    map<string, City*> getCities();
    set<Pipe*> getPipes();
    map<string, Reservoir*> getReservoirs();
    map<string, Station*> getStations();

    City findCity(string code);
    Reservoir findReservoir(string code);
};


#endif //PROJ1_2324_DATA_H
