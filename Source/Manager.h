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
#include <queue>
#include "map"

class Manager {

public:

    explicit Manager(std::vector<Travel> myTravelList);

    void MaxDimension(int start, int ending);

    void MinTrans(int  start, int ending);

    void GroupPath(int start, int ending, int size);

    void MaxGroupPath(int start, int ending);

    void MinDurationPath(int start, int ending, int size);

    std::vector<Travel> findPath(std::vector<Travel> list, int pos, std::vector<Travel> newqueue, int cap, bool first);
    std::vector<Travel> findPath2(std::vector<Travel> list, int pos, std::vector<Travel> newqueue);

private:
    std::vector<Travel> myTravelList;

};



#endif //DAWork2_MANAGER_H
