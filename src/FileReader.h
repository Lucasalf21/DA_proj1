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
    /**
     * Reads the cities from a file and stores them in the data object. Complexity O(V).
     * @param filename
     */
    void readCities(string filename);
    /**
     * Reads the pipes from a file and stores them in the data object. Complexity O(E).
     * @param filename
     */
    void readPipes(string filename);
    /**
     * Reads the reservoirs from a file and stores them in the data object. Complexity O(V).
     * @param filename
     */
    void readReservoirs(string filename);
    /**
     * Reads the stations from a file and stores them in the data object. Complexity O(V).
     * @param filename
     */
    void readStations(string filename);
};


#endif //PROJ1_2324_FILEREADER_H
