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


    std::cout << "A viagem que leva o maior número de passageiros é " << ( pathFlow[ending].getFlow()) << std::endl;

}



 //-----------------------------------------------



void Manager::MinTrans(int start, int ending) { //Breadth-First Search (BFS)

    std::cout << "Starting spot location: "<< start << std::endl;


    std::vector<Travel> best;  //melhor iteração
    std::vector<Travel> myQueue;  //lista de caminhos por testar
    std::vector<Travel> visited;  //caminhos a serem visitados no momento

    bool terminate = false;  //determina se o ciclo deve acabar
    auto pos = start;  //posição atual
    int icap; //capacidade inicial

    int trans = 0; //n de transbordos atual
    int btrans = 100000;  //recorde de menor n de transbordos

    bool first = false;

    while(!terminate) {
        //checks it is the inicial travel in a cycle
        if(pos == start) {
            first = true;
            visited.clear();
        }else {
            first = false;
        }

        //guarda todas as saidas possiveis
        myQueue = findPath(myTravelList, pos, myQueue, icap, first);

        if(!myQueue.empty()) {
            //torna a ultima viagem em queue em visitada
            for (int i = 0; i < myTravelList.size(); i++) {
                if (myTravelList[i] == myQueue.back()) {
                    myTravelList[i].setVisited(true);
                }
            }

            for (int i = 0; i < myQueue.size(); i++) {
                if (myQueue[i].getOrigin() == pos) {
                    pos = start;
                }
            }
            if (myQueue.back().getOrigin() == start) {
                first = true;
                visited.clear();
                std::cout << " First " << std::endl;
            }

            //guarda a ultima na lista visited o caminho a seguir se
            visited.push_back(myQueue.back());
            //remove o caminho escolhido da Queue
            myQueue.pop_back();
            //define a posição atual como sendo a do destino do caminho escolhido
            pos = visited.back().getDestination();
            //dá um print do caminho escolhido
            std::cout << visited.back().getOrigin() << " -> " << visited.back().getDestination() << std::endl;
        }
        //sets initial capacity to be the same as the start capacity
        if(first) {
            icap = visited.back().getCapacity();
            trans = 0;
        }else {
            trans ++; //incrementa o n de transbordos
        }

        if (pos == ending) {
            std::cout << " One cicle " << std::endl;
            if(trans < btrans) {
                std::cout << " Better " << std::endl;
                best = visited;
                btrans = trans;
                visited.clear();
            }

            pos = myQueue.back().getOrigin();
        }

        //verifica se tem mais caminhos alternativos por testar
        if(myQueue.empty() && myQueue == findPath(myTravelList, pos, myQueue, icap, first)) {
            terminate = true;
        }
    }

    if(best.empty()) {
        std::cout << "No resutls!" << std::endl;
    }else {
        //output
        std::cout << " Trans: " << btrans << std::endl;
        std::cout << "A viagem com o menor número de transbordos é: " << start;
        for (auto a: best) {
            std::cout << " -> " << a.getDestination();
        }
    }

}


std::vector<Travel> Manager::findPath(std::vector<Travel> list, int pos, std::vector<Travel> newqueue, int cap, bool first) {
    for(auto x : list) {
        if(first && x.getOrigin() == pos && !x.getVisited()){ //se for a primeira nao sofre resticoes de capacidade
            newqueue.push_back(x);
        }else if(x.getOrigin() == pos && !x.getVisited() && x.getCapacity() >= cap) {
            newqueue.push_back(x);
        }
    }
    return newqueue;
}


//-------------------------------------------------------------------------------------------------------------

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