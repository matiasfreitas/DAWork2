//
// Created by frant on 22/05/2022.
//

#include "Manager.h"
#include "Travels.cpp"

bool Manager::TravelOriginSorter(Travel travel1, Travel travel2) {
    return travel1.getorigin() < travel2.getorigin();
}


void Manager::MaxDimension(std::vector<Travel> &myTravelList){

    std::sort(myTravelList.begin(), myTravelList.end());
    int maxcap = 0;
    int position;

    for (int i = 0; i < myTravelList.size(); i++) {
        if(myTravelList[i].getcapacity() > maxcap){
            maxcap = myTravelList[i].getcapacity();
            position = i;
        }
    }
    std::cout << "A viagem que leva o maior número de passageiros é " << myTravelList[position].getorigin()
              << " " << myTravelList[position].getdestination()
              << " " << myTravelList[position].getcapacity()
              << " " << myTravelList[position].getduration() << std::endl;
}
