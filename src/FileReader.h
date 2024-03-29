//
// Created by lucasalf on 27-03-2024.
//

#ifndef PROJ1_2324_FILEREADER_H
#define PROJ1_2324_FILEREADER_H

#include "Data.h"

class FileReader {
private:
    Data* data;

public:
    FileReader(Data* data);
    void readCities(string filename);
    void readPipes(string filename);
    void readReservoirs(string filename);
    void readStations(string filename);
};


#endif //PROJ1_2324_FILEREADER_H
