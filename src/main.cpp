#include <iostream>
#include "Data.h"
#include "FileReader.h"

using namespace std;

int main() {
    cout << "Welcome to the water supply system!" << endl;

    string directory = "../large_data/";
    Data* data = new Data();
    FileReader* fileReader = new FileReader(data);
    fileReader->readCities(directory);
    fileReader->readPipes(directory);
    fileReader->readReservoirs(directory);
    fileReader->readStations(directory);

    return 0;
}
