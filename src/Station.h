//
// Created by lucasalf on 27-03-2024.
//

#ifndef PROJ1_2324_STATION_H
#define PROJ1_2324_STATION_H

#include <string>

using namespace std;

class Station {
private:
    int id;
    string code;

public:
    Station();
    Station(int id, string code);
    int getId();
    string getCode();
};


#endif //PROJ1_2324_STATION_H
