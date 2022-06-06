#include <iostream>
#include "../Source/Travel.h"
#include "../Source/Reader.h"
#include "../Source/Manager.h"


int main() {

    Reader myReader;
    std::string filename;
    std::vector<Travel> travels;

    filename = "../Data/in02.txt";
    travels = myReader.readTravelInfo(filename);
    Manager manager(travels);
    //std::cout << " CENARIO 1: " << std::endl;
    //manager.MaxDimension(1, 8);
    //manager.MinTrans(1, 8);
    //std::cout << " CENARIO 2: " << std::endl;
    manager.GroupPath(1,8, 5);
    manager.MaxGroupPath(1,8);
    //manager.MinDurationPath(1,8, 5);

    return 0;
}

