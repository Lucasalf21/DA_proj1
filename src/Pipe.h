//
// Created by lucasalf on 27-03-2024.
//

#ifndef PROJ1_2324_PIPE_H
#define PROJ1_2324_PIPE_H

#include <string>

using namespace std;

class Pipe {
private:
    string serviceA;
    string serviceB;
    int capacity;
    int direction;

public:
    Pipe();
    Pipe(string serviceA, string serviceB, int capacity, int direction);
    string getServiceA();
    string getServiceB();
    int getCapacity();
    int getDirection();
};


#endif //PROJ1_2324_PIPE_H
