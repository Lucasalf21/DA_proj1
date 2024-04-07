#include <iostream>
#include "Data.h"
#include "FileReader.h"
#include "GraphLoader.h"
#include "Menu.h"

using namespace std;

int main() {
    string directory = "../large_data/";
    Data* data = new Data();
    auto* g = new Graph<string>();
    auto* fileReader = new FileReader(data);
    auto* graphLoader = new GraphLoader(data, g);

    fileReader->readCities(directory);
    fileReader->readPipes(directory);
    fileReader->readReservoirs(directory);
    fileReader->readStations(directory);
    graphLoader->loadVertex();
    graphLoader->loadPipes();

    cout << " Welcome to the Water Supply Management System!" << endl;

    Menu menu(data, g);

    return 0;
}
