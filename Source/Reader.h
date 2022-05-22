//
// Created by frant on 22/05/2022.
//
#include <vector>
#include <fstream>
#ifndef DAWork2_READER_H
#define DAWork2_READER_H

/**
 * This class is the reader with its methods to ble able to read the files
 */
class Reader {
public:
    static std::vector<Travel> readTravelInfo(std::string filename, char delimeter = ',');

};



#endif //DAWork2_READER_H
