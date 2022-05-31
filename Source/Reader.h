//
// Created by frant on 22/05/2022.
//

#ifndef READER
#define READER

#include <vector>
#include "Travels.h"
#include <iostream>
#include <fstream>

/**
 * This class is the reader with its methods to ble able to read the files
 */
class Reader {
public:
    static std::vector<Travel> readTravelInfo(std::string filename, char delimeter = ',');
};

#endif //READER