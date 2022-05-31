//
// Created by frant on 22/05/2022.
//

#include "Manager.h"
#include "Travels.h"

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



void Manager::MaxDimMinTrans(std::vector<Travel> &myTravelList, int start, int ending){
    std::sort(myTravelList.begin(), myTravelList.end(), TravelOriginSorter);
    bool finished;

    int ntrans = -1;

    there:
    int caminho = start;
    int cap = 0;
    int skiped = 0;
    for (int i = 0; i < myTravelList.size(); i++){

            if(myTravelList[i].getOrigin() == caminho && !myTravelList[i].getUsed() && myTravelList[i].getCapacity() >= cap && !myTravelList[i].getBlock()) {
                while(myTravelList[i].getOrigin() == caminho) {
                    if(myTravelList[i].getDestination() == ending) {
                        myTravelList[i].sended();
                        finished = true;
                        goto end;
                    }
                    i++;
                    skiped++;
                }
                i -= skiped;
            }

            if(myTravelList[i].getOrigin() == caminho && !myTravelList[i].getUsed() && myTravelList[i].getCapacity() >= cap && !myTravelList[i].getBlock()) {
            caminho = myTravelList[i].getDestination();
            myTravelList[i].sended();

            if(myTravelList[i].getDestination() == ending) {
                finished = true;
                break;
            }
        }

        if(myTravelList[i].getOrigin() == start && myTravelList[i].getUsed() && !myTravelList[i].getBlock()) {
            cap = myTravelList[i].getCapacity();
        }
    }

    if(!finished) {
            for (int i = 0; i < myTravelList.size(); i++) {
                if (myTravelList[i].getUsed()) {
                    myTravelList[i].block();
                    myTravelList[i].reset();
                }
            }
        goto there;
    }



    end:
    if(finished) {

        for (int i = 0; i < myTravelList.size(); i++) {
            if (myTravelList[i].getUsed()) {
                ntrans++;
            }
        }

        std::cout << " A viagem com o menor numero de transbordos " << ntrans << std::endl;
        for (int i = 0; i < myTravelList.size(); i++) {
            if (myTravelList[i].getUsed()) {
                std::cout << myTravelList[i].getOrigin()
                          << " " << myTravelList[i].getDestination()
                          << " " << myTravelList[i].getCapacity()
                          << " " << myTravelList[i].getDuration() << std::endl;
            }
        }
    }else {
        std::cout << "Não existe um caminho" << std::endl;
    }
}

