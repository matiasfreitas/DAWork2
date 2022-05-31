//
// Created by frant on 22/05/2022.
//

#include "Manager.h"

bool Manager::TravelOriginSorter(Travel travel1, Travel travel2) {
    return travel1.getOrigin() < travel2.getOrigin() && travel1.getDestination() < travel2.getDestination();
}


void Manager::MaxDimension(std::vector<Travel> &myTravelList){
    std::sort(myTravelList.begin(), myTravelList.end());
    int maxcap = 0;
    int position;

    for (int i = 0; i < myTravelList.size(); i++) {
        if(myTravelList[i].getCapacity() > maxcap){
            maxcap = myTravelList[i].getCapacity();
            position = i;
        }
    }



    std::cout << "A viagem que leva o maior número de passageiros é " << myTravelList[position].getOrigin()
              << " " << myTravelList[position].getDestination()
              << " " << myTravelList[position].getCapacity()
              << " " << myTravelList[position].getDuration() << std::endl;

}



void Manager::MaxDimMinTrans(int start, int ending){


    auto spotStart = mySpotsList.find(Spots(start));
    std::vector<Spots> visited = {};

    std::vector<Travel> paths = minPath(spotStart, ending, visited); //distance vector

}
std::vector<Travel>  Manager::minPath(Spots spotStart, int ending, std::vector<Spots> visited){
    visited.push_back(spotStart);
    if(spotStart.getLocation() == ending){
        return visited;
    }
    else {
        for (auto path: spotStart.getPaths()) {
            auto spotNext = mySpotsList.find(Spots(path.getDestination()));
            std::vector<Travel> paths = minPath(spotNext, ending, visited);

        }
    }


}
Manager::Manager(std::vector<Travel> myTravelList) :myTravelList(myTravelList){
    for (auto travel: myTravelList) {
        mySpotsList.insert(Spots(travel.getDestination()));
        mySpotsList.insert(Spots(travel.getOrigin()));
    }
    for (auto spot: mySpotsList) {
        for (auto travel: myTravelList) {
            if (travel.getOrigin() == spot.getLocation()){
                spot.addPath(travel);
            }
        }
    }



}

