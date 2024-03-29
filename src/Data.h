//
// Created by lucasalf on 28-03-2024.
//

#ifndef PROJ1_2324_DATA_H
#define PROJ1_2324_DATA_H

#include "City.h"
#include "Pipe.h"
#include "Reservoir.h"
#include "Station.h"
#include <set>

using namespace std;

class Data {
private:
    set<City*> cities;
    set<Pipe*> pipes;
    set<Reservoir*> reservoirs;
    set<Station*> stations;

public:
    Data();
    void newCity(City* city);
    void newPipe(Pipe* pipe);
    void newReservoir(Reservoir* reservoir);
    void newStation(Station* station);
    set<City*> getCities();
    set<Pipe*> getPipes();
    set<Reservoir*> getReservoirs();
    set<Station*> getStations();
};


#endif //PROJ1_2324_DATA_H
