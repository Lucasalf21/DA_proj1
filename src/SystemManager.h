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
    /**
     * @brief Calculate the max flow to each city using the Edmonds-Karp algorithm. Complexity O(V * E^2).
     * @param g The graph with the cities, reservoirs, stations and pipes.
     */
    void edmondsKarp(Graph<std::string> g, Data* data);
};


#endif //PROJ1_2324_SYSTEMMANAGER_H
