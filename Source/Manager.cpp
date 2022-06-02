//
// Created by frant on 22/05/2022.
//

#include <list>
#include "Manager.h"

bool Manager::TravelOriginSorter(Travel travel1, Travel travel2) {
    return travel1.getOrigin() < travel2.getOrigin() && travel1.getDestination() < travel2.getDestination();
}


void Manager::MaxDimension(Spots start, Spots ending){
    start = *std::find(mySpotsList.begin(), mySpotsList.end(), start);
    std::map<Spots, std::tuple<Spots, int>> pathFlow; // pat
    std::deque<std::tuple<int, Spots>> myQueue;

    for (const auto spot: mySpotsList) {
        pathFlow.insert({spot, {NULL,0}});
    }
    myQueue.push_back({INT32_MAX, start});
    pathFlow[start] = {NULL, INT32_MAX};
    std::tuple<int, Spots> nextVertice;
    int flow;
    while(!myQueue.empty()){
        nextVertice = myQueue.front();
        myQueue.pop_front();
        std::cout << std::get<0>(nextVertice) << " " << std::endl;
        for (auto path: std::get<1>(nextVertice).getPaths()) {
            //if capacity of path is greater than capacity on pathflow (max flow in that interaction) of the destination of the pat
            // and capacity of path is greater than capacity on pathflow (max flow in that interaction) of the destination of the pat
            std::cout << path.getCapacity() << " " << std::get<1>(pathFlow[path.getDestination()]) << " "
                      << std::get<0>(nextVertice) << std::endl;
            if (path.getCapacity() > std::get<1>(pathFlow[path.getDestination()]) &&
                std::get<0>(nextVertice) > std::get<1>(pathFlow[path.getDestination()])) {
            pathFlow[path.getDestination()] = {std::get<1>(nextVertice),
                                               std::min(path.getCapacity(), std::get<0>(nextVertice))};
            }
            myQueue.push_back({std::min(path.getCapacity(), std::get<0>(nextVertice)),
                               *std::find(mySpotsList.begin(), mySpotsList.end(), Spots(path.getDestination()))});
        }
    }


    std::cout << "A viagem que leva o maior número de passageiros é " << std::get<1>( pathFlow[ending]);

}



void Manager::MaxDimMinTrans(std::vector<Travel> &myTravelList, int start, int ending){


    std::vector<Spots> visited = {};

}
Manager::Manager(std::vector<Travel> myTravelList) :myTravelList(myTravelList){
    for (Travel travel: myTravelList) {
        if (mySpotsList.end() != std::find(mySpotsList.begin(), mySpotsList.end(), Spots(travel.getOrigin()))){
            std::find(mySpotsList.begin(),mySpotsList.end(), Spots(travel.getOrigin()))->addPath(travel);
        }
        else{
            mySpotsList.push_back(Spots(travel.getOrigin()));
            std::find(mySpotsList.begin(),mySpotsList.end(), Spots(travel.getOrigin()))->addPath(travel);
        }
        if (mySpotsList.end() == std::find(mySpotsList.begin(), mySpotsList.end(), Spots(travel.getDestination()))){
            mySpotsList.push_back(Spots(travel.getDestination()));
        }


    }

}

std::vector<Spots> &Manager::getMySpotsList(){
    return mySpotsList;
}

