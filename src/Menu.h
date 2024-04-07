//
// Created by lucasalf on 27-03-2024.
//

#ifndef PROJ1_2324_MENU_H
#define PROJ1_2324_MENU_H


#include "Data.h"
#include "Graph.h"

class Menu {
private:
    Data* data;
    Graph<string>* g;

public:
    Menu(Data* data, Graph<string>* g);

    /**
     * @brief Basic Metric Services. Runs an Edmonds-Karp algorithm to store the city-flow pairs. Complexity O(V * E^2).
     */
    void choice1();
    /**
     * @brief Determines the maximum amount of water that can reach a specific city. Complexity O(V).
     * @param res A set of pairs with the city code and the maximum amount of water that can reach it.
     */
    void maximumAmountOfWaterSpecific(set<pair<string, double>> res);
    /**
     * @brief Determines the maximum amount of water that can reach each city. Complexity O(V).
     * @param res A set of pairs with the city code and the maximum amount of water that can reach it.
     * @param total The total amount of water that can reach all cities.
     */
    void maximumAmountOfWaterEach(set<pair<string, double>> res, double total);
    /**
     * @brief Determines which cities do not reach their demand. Complexity O(V).
     * @param res A set of pairs with the city code and the maximum amount of water that can reach it.
     */
    void deficitInEach(set<pair<string, double>> res);

    /**
     * @brief Reliability and Sensitivity to Failures. Runs an Edmonds-Karp algorithm to store the city-flow pairs. Complexity O(V * E^2).
     */
    void choice2();
    /**
     * @brief Removes a reservoir from the graph and recalculates the maximum flow. Complexity O(V * E^2 + V^2).
     * @param originalMaxFlow A set of pairs with the city code and the maximum amount of water that can reach it.
     */
    void removeReservoir(set<pair<string, double>> originalMaxFlow);
    /**
     * @brief Removes a station from the graph and recalculates the maximum flow. Complexity O(V * E^2 + V^2).
     * @param originalMaxFlow A set of pairs with the city code and the maximum amount of water that can reach it.
     */
    void removeStation(set<pair<string, double>> originalMaxFlow);
    /**
     * @brief Removes one or more pipes from the graph and recalculates the maximum flow. Complexity O(V * E^2 + V^2).
     * @param originalMaxFlow A set of pairs with the city code and the maximum amount of water that can reach it.
     */
    void removePipe(set<pair<string, double>> originalMaxFlow);
};


#endif //PROJ1_2324_MENU_H
