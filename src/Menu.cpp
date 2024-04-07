//
// Created by lucasalf on 27-03-2024.
//

#include "Menu.h"
#include "SystemManager.h"

Menu::Menu(Data *data, Graph<string> *g) {
    this->data = data;
    this->g = g;
    char choice;

    while (true) {
        cout << endl << " _______________________________MAIN MENU______________________________ " << endl
             << "1 - Basic Service Metrics" << endl
             << "2 - Reliability and Sensitivity to Failures" << endl

             << endl << "0 - Exit" << endl
             << " ______________________________________________________________________ " << endl << endl

             << "Please choose the desired option: ";
        cin >> choice;
        switch (choice) {
            case '1':
                choice1();
                break;

            case '2':
                choice2();
                break;

            case '0':
                exit(0);
            default:
                cout << "Invalid option!" << endl;
        }
    }
}

void Menu::choice1() {
    set<pair<string, double>> res;
    double total = 0;
    SystemManager sm;
    Graph<string> copy = g->cloneGraph();
    sm.edmondsKarp(copy, data);

    for (auto v: copy.getVertexSet()) {
        if (v->getInfo()[0] == 'C') {
            for (auto e: v->getAdj()) {
                res.insert(make_pair(v->getInfo(), e->getFlow()));
                total += e->getFlow();
            }
        }
    }

    char choice;
    while (true) {
        cout << endl << " ________________________BASIC SERVICE METRICS_________________________ " << endl
             << "1 - Determine the maximum amount of water that can reach a specific city" << endl
             << "2 - Determine the maximum amount of water that can reach each city" << endl
             << "3 - Check deficit in each city" << endl

             << endl << "9 - Return to the previous menu" << endl
             << "0 - Exit" << endl
             << " ______________________________________________________________________ " << endl << endl

             << "Please choose the desired option: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
            case '1':
                maximumAmountOfWaterSpecific(res);
                break;
            case '2':
                maximumAmountOfWaterEach(res, total);
                break;

            case '3':
                deficitInEach(res);
                break;

            case '9':
                return;
            case '0':
                exit(0);
            default:
                cout << "Invalid option!" << endl;
        }
    }
}

void Menu::maximumAmountOfWaterSpecific(set<pair<string, double>> res) {
    string city;
    cout << "Please enter the city code (C_x): ";
    cin >> city;

    if (g->findVertex(city) == nullptr){
        cout << "City not found!" << endl;
        return;
    }

    for (const auto& p : res){
        if (p.first == city){
            cout << data->findCity(p.first)->getName() << " - " << p.second << " m3" << endl;
            return;
        }
    }
}

void Menu::maximumAmountOfWaterEach(set<pair<string, double>> res, double total) {
    for (const auto& p : res){
        cout << data->findCity(p.first)->getName() << " - " << p.second << " m3" << endl;
    }
    cout << endl << "Total: " << total << " m3" << endl;
}

void Menu::deficitInEach(set<pair<string, double>> res) {
    for (auto p : res){
        double deficit = data->findCity(p.first)->getDemand() - p.second;
        if (deficit > 0){
            cout << data->findCity(p.first)->getName() << ": " << endl
                 << "- Demand: " << data->findCity(p.first)->getDemand() << " m3" << endl
                 << "- Actual Flow: " << p.second << " m3" << endl
                 << "- Deficit: " << deficit << " m3" << endl
                 << endl;
        }
    }
}

void Menu::choice2() {
    set<pair<string, double>> originalMaxFlow;
    SystemManager sm;
    Graph<string> copy = g->cloneGraph();
    sm.edmondsKarp(copy, data);

    for (auto v: copy.getVertexSet()) {
        if (v->getInfo()[0] == 'C') {
            for (auto e: v->getAdj()) {
                originalMaxFlow.insert(make_pair(v->getInfo(), e->getFlow()));
            }
        }
    }


    char choice;
    while (true) {
        cout << endl << " _______________RELIABILITY AND SENSITIVITY TO FAILURES________________ " << endl
             << "1 - Remove a reservoir" << endl
             << "2 - Remove a pumping station" << endl
             << "3 - Remove one or more pipes" << endl

             << endl << "9 - Return to the previous menu" << endl
             << "0 - Exit" << endl
             << " ______________________________________________________________________ " << endl << endl

             << "Please choose the desired option: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
            case '1':
                removeReservoir(originalMaxFlow);
                break;
            case '2':
                removeStation(originalMaxFlow);
                break;
            case '3':
                removePipe(originalMaxFlow);
                break;

            case '9':
                return;
            case '0':
                exit(0);
            default:
                cout << "Invalid option!" << endl;
        }
    }
}

void Menu::removeReservoir(set<pair<string, double>> originalMaxFlow) {
    set<pair<string, double>> newMaxFlow;
    Graph<string> copy = g->cloneGraph();
    SystemManager sm;
    string reservoir;
    cout << "Please enter the reservoir code (R_x): ";
    cin >> reservoir;

    if (copy.findVertex(reservoir) == nullptr){
        cout << "Reservoir not found!" << endl;
        return;
    }

    copy.removeVertex(reservoir);
    sm.edmondsKarp(copy, data);

    for (auto v: copy.getVertexSet()) {
        if (v->getInfo()[0] == 'C') {
            for (auto e: v->getAdj()) {
                newMaxFlow.insert(make_pair(v->getInfo(), e->getFlow()));
            }
        }
    }

    if (newMaxFlow == originalMaxFlow){
        cout << endl << "No cities were affected." << endl;
        return;
    }
    cout << endl << "Cities that were affected: " << endl;
    for (auto p1 : originalMaxFlow){
        for (auto p2 : newMaxFlow){
            if (p1.first == p2.first && p1.second != p2.second){
                cout << data->findCity(p1.first)->getName() << ": " << endl
                     << "- Old Flow: " << p1.second << " m3" << endl
                     << "- New Flow: " << p2.second << " m3" << endl << endl;
            }
        }
    }
}

void Menu::removeStation(set<pair<string, double>> originalMaxFlow) {
    set<pair<string, double>> newMaxFlow;
    Graph<string> copy = g->cloneGraph();
    SystemManager sm;
    string station;
    cout << "Please enter the station code (PS_x): ";
    cin >> station;

    if (copy.findVertex(station) == nullptr){
        cout << "Station not found!" << endl;
        return;
    }

    copy.removeVertex(station);
    sm.edmondsKarp(copy, data);

    for (auto v: copy.getVertexSet()) {
        if (v->getInfo()[0] == 'C') {
            for (auto e: v->getAdj()) {
                newMaxFlow.insert(make_pair(v->getInfo(), e->getFlow()));
            }
        }
    }

    if (newMaxFlow == originalMaxFlow){
        cout << endl << "No cities were affected." << endl;
        return;
    }
    cout << endl << "Cities that were affected: " << endl;
    for (auto p1 : originalMaxFlow){
        for (auto p2 : newMaxFlow){
            if (p1.first == p2.first && p1.second != p2.second){
                cout << data->findCity(p1.first)->getName() << ": " << endl
                     << "- Old Flow: " << p1.second << " m3" << endl
                     << "- New Flow: " << p2.second << " m3" << endl << endl;
            }
        }
    }
}

void Menu::removePipe(set<pair<string, double>> originalMaxFlow) {
    set<pair<string, double>> newMaxFlow;
    Graph<string> copy = g->cloneGraph();
    SystemManager sm;

    int n;
    cout << "Please enter the number of pipes to remove: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string pipeA, pipeB;
        cout << "Please enter pipe " << i + 1 << " origin's code: ";
        cin >> pipeA;
        cout << "Please enter the pipe " << i + 1 << " destination's code: ";
        cin >> pipeB;

        if (!copy.findEdge(pipeA, pipeB)) {
            cout << "Pipe not found!" << endl;
            return;
        }

        bool bidirectional = false;
        if (copy.findEdge(pipeA, pipeB) == copy.findEdge(pipeB, pipeA)) {
            bidirectional = true;
        }

        copy.removeEdge(pipeA, pipeB);
        if (bidirectional) {
            copy.removeEdge(pipeB, pipeA);
        }
    }

    sm.edmondsKarp(copy, data);

    for (auto v: copy.getVertexSet()) {
        if (v->getInfo()[0] == 'C') {
            for (auto e: v->getAdj()) {
                newMaxFlow.insert(make_pair(v->getInfo(), e->getFlow()));
            }
        }
    }

    if (newMaxFlow == originalMaxFlow){
        cout << endl << "No cities were affected." << endl;
        return;
    }
    cout << endl << "Cities that were affected: " << endl;
    for (auto p1 : originalMaxFlow){
        for (auto p2 : newMaxFlow){
            if (p1.first == p2.first && p1.second != p2.second){
                cout << data->findCity(p1.first)->getName() << ": " << endl
                     << "- Old Flow: " << p1.second << " m3" << endl
                     << "- New Flow: " << p2.second << " m3" << endl << endl;
            }
        }
    }
}