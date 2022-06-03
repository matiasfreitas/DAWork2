//
// Created by frant on 22/05/2022.
//

#include <list>
#include "Manager.h"
#include "pathCalculator.h"

bool Manager::TravelOriginSorter(Travel travel1, Travel travel2) {
    return travel1.getOrigin() < travel2.getOrigin() && travel1.getDestination() < travel2.getDestination();
}


void Manager::MaxDimension(Spots start, Spots ending){
    start = *std::find(mySpotsList.begin(), mySpotsList.end(), start);
    std::map<Spots, pathCalculator> pathFlow;  //Father, flow, itself
    std::vector<pathCalculator> myQueue; //Father, flow, itself
    for (const auto &spot: mySpotsList) {
        pathFlow.insert({spot, pathCalculator(0, spot)});
        if (spot != start){
            myQueue.push_back(pathFlow[spot]);
        }
    }

    pathFlow[start] = pathCalculator(start, INT32_MAX, start);
    myQueue.push_back(pathCalculator(start, INT32_MAX, start));
    pathCalculator nextVertice;
    int flow;
    while(!myQueue.empty()){
        std::sort(myQueue.rbegin(), myQueue.rend());
        nextVertice = *myQueue.begin();

        std::cout << nextVertice.getFlow() << " " << std::endl;

        for (auto path: nextVertice.getDestiny().getPaths()) {
            //if capacity of path is greater than capacity on pathflow (max flow in that interaction) of the destination of the pat
            // and capacity of path is greater than capacity on pathflow (max flow in that interaction) of the destination of the pat
            std::cout << path.getCapacity() << " " << pathFlow[path.getDestination()].getFlow() << " "
                      << nextVertice.getFlow() << std::endl;
            if (path.getCapacity() > pathFlow[path.getDestination()].getFlow() &&
                    nextVertice.getFlow() > pathFlow[path.getDestination()].getFlow()) {

                pathFlow[path.getDestination()] = pathCalculator(nextVertice.getOrigin(),
                                                    std::min(path.getCapacity(), nextVertice.getFlow()),
                                                                 *std::find(mySpotsList.begin(), mySpotsList.end(), Spots(path.getDestination())));

                myQueue.erase(std::find(myQueue.begin(), myQueue.end(), Spots(nextVertice.getOrigin())));
                myQueue.push_back(pathCalculator(nextVertice.getOrigin(),
                                                 std::min(path.getCapacity(), nextVertice.getFlow()),
                                                 *std::find(mySpotsList.begin(), mySpotsList.end(), Spots(path.getDestination()))));
            }

        }
        myQueue.erase(myQueue.begin());
    }


    std::cout << "A viagem que leva o maior número de passageiros é " << ( pathFlow[ending].getFlow());

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

