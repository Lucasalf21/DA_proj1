//
// Created by lucasalf on 27-03-2024.
//

#ifndef PROJ1_2324_RESERVOIR_H
#define PROJ1_2324_RESERVOIR_H

#include <string>

using namespace std;

class Reservoir {
private:
    string name;
    string municipality;
    int id;
    string code;
    int maxDelivery;

public:
    Reservoir();
    Reservoir(string name, string municipality, int id, string code, int maxDelivery);
    string getName();
    string getMunicipality();
    int getId();
    string getCode();
    int getMaxDelivery();
};


#endif //PROJ1_2324_RESERVOIR_H
