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
#include <queue>
#include "map"

class Manager {

public:
    void MaxDimension(int start, int ending);
    bool static TravelOriginSorter(Travel travel1, Travel travel2);
    // void resetCouriers(std::vector<Courier> &myCourierList);


    explicit Manager(std::vector<Travel> myTravelList);
    Spots discoverPath(std::vector<Spots> mySpotsList, Spots pos, int capacity, Spots ending);
    std::vector<Spots> &getMySpotsList();

    void MinTrans(int  start, int ending);

    void GroupPath(int start, int ending, int size);
    std::vector<Travel> findPath(std::vector<Travel> list, int pos, std::vector<Travel> newqueue, int cap, bool first);
    std::vector<Travel> findPath2(std::vector<Travel> list, int pos, std::vector<Travel> newqueue, int cap, bool first);

private:
    std::vector<Travel> myTravelList;
    std::vector<Spots> mySpotsList;


};



#endif //DAWork2_MANAGER_H
