//
// Created by lucasalf on 27-03-2024.
//

#include "FileReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

FileReader::FileReader(Data *data) {
    this->data = data;
}

void FileReader::readCities(std::string filename) {
    filename += "Cities.csv";
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file!" << filename << endl;
        return;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string name, id, code, demand, population;

        getline(ss, name, ',');
        getline(ss, id, ',');
        getline(ss, code, ',');
        getline(ss, demand, ',');
        getline(ss, population, '\r');

        City* city = new City(name, stoi(id), code, stoi(demand), stoi(population));
        data->newCity(city, code);
    }

    file.close();
}

void FileReader::readPipes(std::string filename) {
    filename += "Pipes.csv";
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file!" << filename << endl;
        return;
    }

    string line;
    getline(file, line);

    while (getline(file, line)){
        stringstream ss(line);
        string serviceA, serviceB, capacity, direction;

        getline(ss, serviceA, ',');
        getline(ss, serviceB, ',');
        getline(ss, capacity, ',');
        getline(ss, direction, '\r');

        Pipe* pipe = new Pipe(serviceA, serviceB, stoi(capacity), stoi(direction));
        data->newPipe(pipe);
    }

    file.close();
}

void FileReader::readReservoirs(std::string filename) {
    filename += "Reservoir.csv";
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file!" << filename << endl;
        return;
    }

    string line;
    getline(file, line);

    while (getline(file, line)){
        stringstream ss(line);
        string name, municipality, id, code, maxDelivery;

        getline(ss, name, ',');
        getline(ss, municipality, ',');
        getline(ss, id, ',');
        getline(ss, code, ',');
        getline(ss, maxDelivery, '\r');

        Reservoir* reservoir = new Reservoir(name, municipality, stoi(id), code, stoi(maxDelivery));
        data->newReservoir(reservoir, code);
    }

    file.close();
}

void FileReader::readStations(std::string filename) {
    filename += "Stations.csv";
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file!" << filename << endl;
        return;
    }

    string line;
    getline(file, line);

    while (getline(file, line)){
        stringstream ss(line);
        string id, code;

        getline(ss, id, ',');
        getline(ss, code, '\r');

        Station* station = new Station(stoi(id), code);
        data->newStation(station, code);
    }

    file.close();
}