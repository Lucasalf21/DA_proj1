//
// Created by lucasalf on 06-04-2024.
//

#ifndef PROJ1_2324_SYSTEMMANAGER_H
#define PROJ1_2324_SYSTEMMANAGER_H

#include "Graph.h"
#include "Data.h"

class SystemManager {
public:
    SystemManager();
    void edmondsKarp(Graph<std::string> g, Data* data);
};


#endif //PROJ1_2324_SYSTEMMANAGER_H
