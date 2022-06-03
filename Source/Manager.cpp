//
// Created by frant on 22/05/2022.
//

#include <list>
#include "Manager.h"
#include "pathCalculator.h"

bool Manager::TravelOriginSorter(Travel travel1, Travel travel2) {
    return travel1.getOrigin() < travel2.getOrigin() && travel1.getDestination() < travel2.getDestination();
}

/*
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


    std::cout << "A viagem que leva o maior número de passageiros é " << ( pathFlow[ending].getFlow()) << std::endl;

}

*/

 //-----------------------------------------------



void Manager::MinTrans(int start, int ending) { //Breadth-First Search (BFS)

    std::cout << "Starting spot location: "<< start << std::endl;


    std::vector<Travel> best;
    std::vector<Travel> myQueue;
    std::vector<Travel> visited;

    bool terminate = false;
    auto pos = start;
    int icap = 0;

    int trans = 0;
    int btrans = 100000;

    while(!terminate) {
        //guarda todas as saidas vizinhas
        myQueue = findPath(myTravelList, pos, myQueue);

        for(int i = 0; i<myTravelList.size(); i++) {
            if(myTravelList[i] == myQueue.back()) {
                myTravelList[i].setVisited(true);
            }
        }
        visited.push_back(myQueue.back());
        trans++;
        //icap = myQueue.back().getCapacity();
        myQueue.pop_back();
        pos = visited.back().getDestination();
        std::cout << visited.back().getOrigin() << " -> " << visited.back().getDestination() << std::endl;
        if (pos == ending) {
            std::cout << " One cicle " << std::endl;
            if(trans < btrans) {
                std::cout << " Better " << std::endl;
                best = visited;
                btrans = trans;
                visited.clear();
            }
            pos = myQueue.back().getOrigin();
            if(pos == start) {
                icap = myQueue.back().getCapacity();
            }
            trans = 0;
        }

        if(myQueue.empty()) {
            terminate = true;
        }
    }





    while(!myQueue.empty()) {
        Travel x = myQueue.back();
        myQueue.pop_back();
        std::cout << " InQueue: " << x << std::endl;
    }




    if(trans != 0) {
        trans--;
    }
    std::cout << " Trans: " << trans << std::endl;
    std::cout << "A viagem com o menor número de transbordos é: " << start;
    for(auto a : best) {
        std::cout << " -> " << a.getDestination();
    }

}


std::vector<Travel> Manager::findPath(std::vector<Travel> list, int pos, std::vector<Travel> newqueue) {
    for(auto x : list) {
        if(x.getOrigin() == pos && !x.getVisited()) {
            newqueue.push_back(x);
        }
    }
    return newqueue;
}


Manager::Manager(std::vector<Travel> myTravelList) :myTravelList(myTravelList){
    for (Travel travel: myTravelList) { //adiciona o caminho ao spot se encontrar um spot com location = travel.Origin
        if (mySpotsList.end() != std::find(mySpotsList.begin(), mySpotsList.end(), Spots(travel.getOrigin()))){
            std::find(mySpotsList.begin(),mySpotsList.end(), Spots(travel.getOrigin()))->addPath(travel);
        }
        else{//se nao encontrar um spot com location = travel.Origin adiciona a location ao spot e adiciona o camminho
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
