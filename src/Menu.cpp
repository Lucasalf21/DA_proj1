//
// Created by lucasalf on 27-03-2024.
//

#include "Menu.h"

Menu::Menu(Data *data, Graph<string> *g) {
    this->data = data;
    this->g = g;
    char choice = '1';

    while (true) {
        cout << endl << "(0) Exit" << endl;

        cout << "Please choose the desired option: ";
        cin >> choice;
        switch (choice) {
            case '0':
                exit(0);
                break;
            default:
                cout << "Invalid option!" << endl;
        }
    }
}

