//
// Created by frant on 22/05/2022.
//

#ifndef DAWork2_MANAGER_H
#define DAWork2_MANAGER_H

#include "Travel.h"
#include "vector"
#include <algorithm>
#include <iostream>
#include <set>
#include "Spots.h"

class Manager {

public:
    void MaxDimension(std::vector<Travel> &myTravelList);
    bool static TravelOriginSorter(Travel travel1, Travel travel2);
    // void resetCouriers(std::vector<Courier> &myCourierList);

    void MaxDimMinTrans(std::vector<Travel> &myTravelList, int start, int ending);
    Manager(std::vector<Travel> myTravelList);

private:
    std::vector<Travel> myTravelList;
    std::set<Spots> mySpotsList;


};



#endif //DAWork2_MANAGER_H
