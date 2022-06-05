//
// Created by frant on 22/05/2022.
//

#include "Reader.h"

std::vector<Travel> Reader::readTravelInfo(std::string filename, char delimeter) {
    std::vector<Travel> myTravels;
    std::ifstream my_file;

    my_file.open(filename, std::ios::in);
    if (!my_file) {
        std::cout << "File not exists!" << std::endl;
    } else if (my_file.eof()) {
       std::cout << "File is empty" << std::endl;
    } else {
        std::cout << "Reading file" << std::endl;

        Travel myTravel;
        std::string origin;
        std::string destination;
        std::string capacity;
        std::string duration;

        std::string header;
        std::getline(my_file, header, ' ');
        std::getline(my_file, header, '\n');

        while (!my_file.eof()) {
            std::getline(my_file, origin, ' ');
            std::getline(my_file, destination, ' ');
            std::getline(my_file, capacity, ' ');
            std::getline(my_file, duration, '\n');

            myTravel = Travel(std::stoi(origin), std::stoi(destination), std::stoi(capacity), std::stoi(duration));
            myTravels.push_back(myTravel);
        }
    }
    return myTravels;
}

