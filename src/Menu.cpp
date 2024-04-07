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
        cout << endl << " __________________________________________________ " << endl
             << "1 - Basic Service Metrics" << endl
             << "2 - Reliability and Sensitivity to Failures" << endl

             << endl << "0 - Exit" << endl
             << " __________________________________________________ " << endl << endl

             << "Please choose the desired option: ";
        cin >> choice;
        switch (choice) {
            case '1':
                choice1();
                break;

            case '2':
                cout << "Not implemented yet!" << endl;
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
    SystemManager maxFlow;
    Graph<string> copy = *g;
    maxFlow.edmondsKarp(&copy, data);
    total = 0;

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
        cout << endl << " __________________________________________________ " << endl
             << "1 - Determine the maximum amount of water in a specific city" << endl
             << "2 - Determine the maximum amount of water in each city" << endl
             << "3 - Check deficit in each city" << endl

             << endl << "9 - Return to the previous menu" << endl
             << "0 - Exit" << endl
             << " __________________________________________________ " << endl << endl

             << "Please choose the desired option: ";
        cin >> choice;
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
    cout << "Please enter the city code: ";
    cin >> city;

    for (const auto& p : res){
        if (p.first == city){
            cout << data->findCity(p.first).getName() << " - " << p.second << " m3" << endl;
            return;
        }
    }
}

void Menu::maximumAmountOfWaterEach(set<pair<string, double>> res, double total) {
    for (const auto& p : res){
        cout << data->findCity(p.first).getName() << " - " << p.second << " m3" << endl;
    }
    cout << "Total: " << total << " m3" << endl;
}

void Menu::deficitInEach(set<pair<string, double>> res) {
    for (auto p : res){
        double deficit = data->findCity(p.first).getDemand() - p.second;
        if (deficit > 0){
            cout << data->findCity(p.first).getName() << ": " << endl
                 << "- Demand: " << data->findCity(p.first).getDemand() << " m3" << endl
                 << "- Actual Flow: " << p.second << " m3" << endl
                 << "- Deficit: " << deficit << " m3" << endl << endl;
        }
    }
}