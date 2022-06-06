//
// Created by frant on 22/05/2022.
//

#include <list>
#include "Manager.h"


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

std::vector<Travel> Manager::findPath2(std::vector<Travel> list, int pos, std::vector<Travel> newqueue) {
    for(auto x : list) {
        if(x.getOrigin() == pos && !x.getVisited()) {
            newqueue.push_back(x);
        }
    }
    return newqueue;
}


void Manager::MaxDimension(int start, int ending){

    for (int i = 0; i < myTravelList.size(); i++) {
        myTravelList[i].setVisited(false);
    }

    std::vector<Travel> best;  //melhor iteração
    std::vector<Travel> myQueue;  //lista de caminhos por testar
    std::vector<Travel> visited;  //caminhos a serem visitados no momento

    bool terminate = false;  //determina se o ciclo deve acabar
    auto pos = start;  //posição atual
    int icap; //capacidade inicial
    int bcap = 0; //melhor capacidade

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
            }

            //guarda a ultima na lista visited o caminho a seguir se
            visited.push_back(myQueue.back());
            //remove o caminho escolhido da Queue
            myQueue.pop_back();
            //define a posição atual como sendo a do destino do caminho escolhido
            pos = visited.back().getDestination();
            //dá um print do caminho escolhido
        }
        //sets initial capacity to be the same as the start capacity
        if(first) {
            icap = visited.back().getCapacity();
        }

        if (pos == ending) {
            if(icap > bcap) {
                best = visited;
                bcap = icap;
                visited.clear();
            }

            pos = myQueue.back().getOrigin();
        }

        //verifica se tem mais caminhos alternativos por testar
        if(myQueue.empty() && myQueue == findPath(myTravelList, pos, myQueue, icap, first)) {
            terminate = true;
        }
    }

    //output
    if(best.empty()) {
        std::cout << "No resutls!" << std::endl;
    }else {
        std::cout << "A viagem que leva o maior número de passageiros é: " << start;
        for (auto a: best) {
            std::cout << " -> " << a.getDestination();
        }
        std::cout << " Numero de passageiros: " << bcap << std::endl;
    }
}

//-------------------------------------------------------------------------------------

void Manager::MinTrans(int start, int ending) { //Breadth-First Search (BFS)

    for (int i = 0; i < myTravelList.size(); i++) {
        myTravelList[i].setVisited(false);
    }

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
            }

            //guarda a ultima na lista visited o caminho a seguir se
            visited.push_back(myQueue.back());
            //remove o caminho escolhido da Queue
            myQueue.pop_back();
            //define a posição atual como sendo a do destino do caminho escolhido
            pos = visited.back().getDestination();
            //dá um print do caminho escolhido
        }
        //sets initial capacity to be the same as the start capacity
        if(first) {
            icap = visited.back().getCapacity();
            trans = 0;
        }else {
            trans ++; //incrementa o n de transbordos
        }

        if (pos == ending) {
            if(trans < btrans) {
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
        std::cout << "A viagem com o menor número de transbordos é: " << start;
        for (auto a: best) {
            std::cout << " -> " << a.getDestination();
        }
        std::cout << " Trans: " << btrans << std::endl;
    }

}

void Manager::MinDurationPath(int start, int ending, int size) {
    for (int i = 0; i < myTravelList.size(); i++) {
        myTravelList[i].setVisited(false);
    }

    std::vector<Travel> best;  //melhor iteração
    std::vector<Travel> myQueue;  //lista de caminhos por testar
    std::vector<Travel> visited;  //caminhos a serem visitados no momento

    bool terminate = false;  //determina se o ciclo deve acabar
    auto pos = start;  //posição atual
    int cap; //capacidade atual
    int time = 0;
    int lastarrival = 0;
    int firstarrival;
    int lastransported = 0;

    while (!terminate) {
        //checks it is the inicial travel in a cycle
        if (pos == start) {
            visited.clear();
            time = 0;
        }

        //guarda todas as saidas possiveis
        myQueue = findPath2(myTravelList, pos, myQueue);

        if (!myQueue.empty()) {
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
                lastransported = myQueue.back().getCapacity();
                cap = lastransported;
                visited.clear();
            }else{
                lastransported = visited.back().getTransportados();
                cap = myQueue.back().getCapacity();
                if(lastransported > cap) {
                    visited.back().setTransportados(lastransported-cap);
                }else {
                    visited.back().setTransportados(0);
                    cap = lastransported;
                }
            }

            //guarda a ultima na lista visited o caminho a seguir se
            visited.push_back(myQueue.back());
            //remove o caminho escolhido da Queue
            myQueue.pop_back();
            //define a posição atual como sendo a do destino do caminho escolhido
            pos = visited.back().getDestination();
            //dá um print do caminho escolhido
        }

        //armazena o valor de pessoas transportadas naquela viagem
        visited.back().setTransportados(cap);
        time += visited.back().getDuration();

        if (pos == ending) {
            if(size > 0) {
                size -= cap;
                if (size < 0) {
                    size = 0;
                }
                best = visited;
                //output
                std::cout << "Viagem de parte do grupo: " << start;
                for (auto x: best) {
                    std::cout << " -> " << x.getDestination();
                }
                std::cout << " Total time: " << time << std::endl;
                if (time > lastarrival) {
                    lastarrival = time;
                }
                if(time < firstarrival) {
                    firstarrival = time;
                }
            }

            pos = myQueue.back().getOrigin();
            while (!visited.empty()) {
                if (pos == visited.back().getOrigin()) {
                    time -= visited.back().getDuration();
                    visited.pop_back();
                    break;
                }
                time -= visited.back().getDuration();
                visited.pop_back();
            }

        }

        //verifica se tem mais caminhos alternativos por testar
        if (myQueue.empty() && myQueue == findPath2(myTravelList, pos, myQueue)) {
            terminate = true;
        }
    }

    if (best.empty()) {
        std::cout << "No resutls!" << std::endl;
    }else {
        std::cout << "The most time waited was " << lastarrival - firstarrival << " minutes "<< std::endl;
    }

}


Manager::Manager(std::vector<Travel> myTravelList) :myTravelList(myTravelList){
    for (Travel travel: myTravelList) { //adiciona o caminho ao spot se encontrar um spot com location = travel.Origin

    }

}


































//------------------------------------------------------------------------------------------------

void Manager::GroupPath(int start, int ending, int size) {

    for (int i = 0; i < myTravelList.size(); i++) {
        myTravelList[i].setVisited(false);
    }

    std::vector<Travel> best;  //melhor iteração
    std::vector<Travel> myQueue;  //lista de caminhos por testar
    std::vector<Travel> visited;  //caminhos a serem visitados no momento

    bool terminate = false;  //determina se o ciclo deve acabar
    auto pos = start;  //posição atual
    int icap; //capacidade inicial
    int cap; //capacidade atual

    int lastransported = 0;
    int transported = 0;

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
        myQueue = findPath2(myTravelList, pos, myQueue);

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
                lastransported = myQueue.back().getCapacity();
                cap = lastransported;
                first = true;
                visited.clear();
            }else{
                lastransported = visited.back().getTransportados();
                cap = myQueue.back().getCapacity();
                if(lastransported > cap) {
                    visited.back().setTransportados(lastransported-cap);
                }else {
                    visited.back().setTransportados(0);
                    cap = lastransported;
                }
            }
            //guarda a ultima na lista visited o caminho a seguir se
            visited.push_back(myQueue.back());
            //remove o caminho escolhido da Queue
            myQueue.pop_back();
            //define a posição atual como sendo a do destino do caminho escolhido
            pos = visited.back().getDestination();
            //dá um print do caminho escolhido
            //std::cout << visited.back().getOrigin() << " -> " << visited.back().getDestination() << std::endl;
        }

        //armazena o valor de pessoas transportadas naquela viagem
        visited.back().setTransportados(cap);
        //std::cout << " visited: " << visited.back().getOrigin() << " -> " << visited.back().getDestination() << " " << visited.back().getTransportados() << std::endl;

        if (pos == ending) {
            //std::cout << " One cicle " << std::endl;
            if(size > 0) {
                std::cout << " Passageiros enviados: " << cap << std::endl;
                size -= cap;
                if (size < 0) {
                    size = 0;
                }
                best = visited;
                btrans = trans;
                //output
                std::cout << "A viagem para um grupo de tamanho definido: " << start;
                for (auto a: best) {
                    std::cout << " -> " << a.getDestination();
                }
                std::cout << " Falta transportar: " << size << std::endl;
            }

            pos = myQueue.back().getOrigin();
            while(!visited.empty()) {
                if (pos == visited.back().getOrigin()) {
                    visited.pop_back();
                    break;
                }
                visited.pop_back();
            }

        }

        //verifica se tem mais caminhos alternativos por testar
        if(myQueue.empty() && myQueue == findPath2(myTravelList, pos, myQueue)) {
            terminate = true;
        }
    }

    if(best.empty()) {
        std::cout << "No resutls!" << std::endl;
    }

}

//-----------------------------------------------------------------------------

void Manager::MaxGroupPath(int start, int ending) {
    std::cout << "MAXGROUPPATH 2.3" << std::endl;
    for (int i = 0; i < myTravelList.size(); i++) {
        myTravelList[i].setVisited(false);
    }

    std::vector<Travel> best;  //melhor iteração
    std::vector<Travel> myQueue;  //lista de caminhos por testar
    std::vector<Travel> visited;  //caminhos a serem visitados no momento

    bool terminate = false;  //determina se o ciclo deve acabar
    auto pos = start;  //posição atual
    int icap; //capacidade inicial
    int cap; //capacidade atual
    int size = 0;

    int lastransported = 0;

    int trans = 0; //n de transbordos atual
    int btrans = 100000;  //recorde de menor n de transbordos

    bool first = false;

    while (!terminate) {
        //checks it is the inicial travel in a cycle
        if (pos == start) {
            first = true;
            visited.clear();
        } else {
            first = false;
        }

        //guarda todas as saidas possiveis
        myQueue = findPath2(myTravelList, pos, myQueue);

        if (!myQueue.empty()) {
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
                lastransported = myQueue.back().getCapacity();
                cap = lastransported;
                first = true;
                visited.clear();
            }else{
                lastransported = visited.back().getTransportados();
                cap = myQueue.back().getCapacity();
                if(lastransported > cap) {
                    visited.back().setTransportados(lastransported-cap);
                }else {
                    visited.back().setTransportados(0);
                    cap = lastransported;
                }
            }

            //guarda a ultima na lista visited o caminho a seguir se
            visited.push_back(myQueue.back());
            //remove o caminho escolhido da Queue
            myQueue.pop_back();
            //define a posição atual como sendo a do destino do caminho escolhido
            pos = visited.back().getDestination();
            //dá um print do caminho escolhido
        }
        //sets initial capacity to be the same as the start capacity
        if (first) {
            icap = visited.back().getCapacity();
            trans = 0;
        }

        //armazena o valor de pessoas transportadas naquela viagem
        visited.back().setTransportados(cap);

        if (pos == ending) {
            if (pos == ending) {
                std::cout << " Passageiros enviados: " << cap << std::endl;
                size += cap;
                btrans = trans;
                //output
                std::cout << "A viagem para o maior grupo possivel: " << start;
                for (auto x: visited) {
                    std::cout << " -> " << x.getDestination();
                }
                std::cout << " Tamanho total do grupo: " << size << std::endl;
            }

            pos = myQueue.back().getOrigin();
            while (!visited.empty()) {
                if (pos == visited.back().getOrigin()) {
                    visited.pop_back();
                    break;
                }
                visited.pop_back();
            }

        }

        //verifica se tem mais caminhos alternativos por testar
        if (myQueue.empty() && myQueue == findPath2(myTravelList, pos, myQueue)) {
            terminate = true;
        }
    }

    if (best.empty()) {
        std::cout << "No resutls!" << std::endl;
    }

}
