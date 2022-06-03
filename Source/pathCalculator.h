//
// Created by matiasfg on 03/06/2022.
//

#ifndef DAWORK2_PATHCALCULATOR_H
#define DAWORK2_PATHCALCULATOR_H


#include "Spots.h"

class pathCalculator {
public:
    pathCalculator(Spots &origin, int distance,  Spots &destiny);

    pathCalculator(int flow,  const  Spots &origin);

    pathCalculator();

    int getFlow()  ;

      Spots &getOrigin()  ;

      Spots &getDestiny()  ;

    void setFlow(int flow);

    void setOrigin(  Spots &origin);

    void setDestiny(  Spots &destiny);

    bool operator==(  pathCalculator &rhs)  ;

    bool operator==(  const Spots &rhs)  ;

    bool operator!=(  pathCalculator &rhs)  ;

    bool operator<(  pathCalculator &rhs)  ;

    bool operator>(  pathCalculator &rhs)  ;

    bool operator<=(  pathCalculator &rhs)  ;

    bool operator>=(  pathCalculator &rhs)  ;

private:
    int flow;
    Spots origin;
    Spots destiny;

};


#endif //DAWORK2_PATHCALCULATOR_H
