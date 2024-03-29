//
// Created by lucasalf on 27-03-2024.
//

#include "Pipe.h"

Pipe::Pipe(std::string serviceA, std::string serviceB, int capacity, int direction) {
    this->serviceA = serviceA;
    this->serviceB = serviceB;
    this->capacity = capacity;
    this->direction = direction;
}

string Pipe::getServiceA() {
    return serviceA;
}

string Pipe::getServiceB() {
    return serviceB;
}

int Pipe::getCapacity() {
    return capacity;
}

int Pipe::getDirection() {
    return direction;
}

Pipe::Pipe() {
    this->serviceA = "";
    this->serviceB = "";
    this->capacity = -1;
    this->direction = -1;
}
