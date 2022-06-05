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

    filename = "../Data/in02.txt";
    travels = myReader.readTravelInfo(filename);
    Manager manager(travels);
    std::cout << " CENARIO 1: " << std::endl;
    manager.MaxDimension(1, 8);
    manager.MinTrans(1, 8);
    std::cout << " CENARIO 2: " << std::endl;
    manager.GroupPath(1,8, 5);

    return 0;
}

