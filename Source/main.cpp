#include <iostream>
#include "../Source/Travels.h"
#include "../Source/Reader.h"
#include "../Source/Manager.h"


int main() {

    Reader myReader;
    std::string filename;
    std::vector<Travel> travels;
    Manager manager;

    std::cout  << std::endl << std::endl << std::endl << std::endl
               << std::endl << "Testing max group dimension" << std::endl;

    filename = "../Data/in02.txt";
    travels = myReader.readTravelInfo(filename);


    //manager.MaxDimension(travels);

    manager.MaxDimMinTrans(travels, 1, 10);

    return 0;
}

