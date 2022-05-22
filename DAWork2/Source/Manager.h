//
// Created by frant on 22/05/2022.
//

#ifndef DAWork2_MANAGER_H
#define DAWork2_MANAGER_H

#include "Travels.h"
#include "vector"
#include <algorithm>
#include <iostream>

class Manager {
public:
    void MaxDimension(std::vector<Travel> &myTravelList);
    bool static TravelOriginSorter(Travel travel1, Travel travel2);
    // void resetCouriers(std::vector<Courier> &myCourierList);


};



#endif //DAWork2_MANAGER_H
