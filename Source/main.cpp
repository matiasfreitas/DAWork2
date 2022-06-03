#include <iostream>
#include "../Source/Travel.h"
#include "../Source/Reader.h"
#include "../Source/Manager.h"


int main() {

    Reader myReader;
    std::string filename;
    std::vector<Travel> travels;


    std::cout  << std::endl << std::endl << std::endl << std::endl
               << std::endl << "Testing max group dimension" << std::endl;

    filename = "../Data/in01.txt";
    travels = myReader.readTravelInfo(filename);
    Manager manager(travels);

    manager.MaxDimension(Spots(1), Spots(5));

    manager.MinTrans(1, 8);

    return 0;
}

