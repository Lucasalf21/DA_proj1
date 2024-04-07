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

    /**
     * @brief Adds a new city to the cities map, with its code as the key. Complexity O(1).
     * @param city The city to be added.
     * @param code The code of the city.
     */
    void newCity(City *city, string code);
    /**
     * @brief Adds a new pipe to the pipes set. Complexity O(1).
     * @param pipe The pipe to be added.
     */
    void newPipe(Pipe *pipe);
    /**
     * @brief Adds a new reservoir to the reservoirs map, with its code as the key. Complexity O(1).
     * @param reservoir The reservoir to be added.
     * @param code The code of the reservoir.
     */
    void newReservoir(Reservoir *reservoir, string code);
    /**
     * @brief Adds a new station to the stations map, with its code as the key. Complexity O(1).
     * @param station The station to be added.
     * @param code The code of the station.
     */
    void newStation(Station *station, string code);
    /**
     * @brief Returns a pointer to the city with the given code. Complexity O(1).
     * @param code The code of the city.
     */
    City* findCity(string code);
    /**
     * @brief Returns a pointer to the reservoir with the given code. Complexity O(1).
     * @param code The code of the reservoir.
     */
    Reservoir* findReservoir(string code);

    map<string, City*> getCities();
    set<Pipe*> getPipes();
    map<string, Reservoir*> getReservoirs();
    map<string, Station*> getStations();
};


#endif //PROJ1_2324_DATA_H
