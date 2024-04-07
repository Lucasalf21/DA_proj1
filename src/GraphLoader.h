//
// Created by lucasalf on 29-03-2024.
//

#ifndef PROJ1_2324_GRAPHLOADER_H
#define PROJ1_2324_GRAPHLOADER_H

#include "Graph.h"
#include "Data.h"

#include <string>
#include <utility>
using namespace std;

class GraphLoader {
private:
    Data* data;
    Graph<string>* g;

public:
    GraphLoader(Data* data, Graph<string>* g);
    /**
     * @brief Loads the cities, reservoirs and pumping stations as vertices of the graph. Complexity O(V).
     */
    void loadVertex();
    /**
     * @brief Loads the pipes as edges of the graph. Complexity O(E).
     */
    void loadPipes();
};


#endif //PROJ1_2324_GRAPHLOADER_H
