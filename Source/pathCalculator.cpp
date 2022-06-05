//
// Created by matiasfg on 03/06/2022.
//

#include "pathCalculator.h"

int pathCalculator::getFlow()   {
    return flow;
}

  Spots &pathCalculator::getOrigin()   {
    return origin;
}

  Spots &pathCalculator::getDestiny()   {
    return destiny;
}

pathCalculator::pathCalculator(Spots &origin, int flow, Spots &destiny) : flow(flow),
                                                                                          origin(origin),
                                                                                          destiny(destiny) {}

void pathCalculator::setFlow(int flow) {
    pathCalculator::flow = flow;
}

void pathCalculator::setOrigin(  Spots &origin) {
    pathCalculator::origin = origin;
}

void pathCalculator::setDestiny(  Spots &destiny) {
    pathCalculator::destiny = destiny;
}

bool pathCalculator::operator==(  pathCalculator &rhs)   {
    return origin == rhs.origin;
}

bool pathCalculator::operator==( const Spots &rhs)   {
    return origin == rhs;
}

bool pathCalculator::operator!=(  pathCalculator &rhs)   {
    return !(rhs == *this);
}

bool pathCalculator::operator<(  pathCalculator &rhs)   {
    return flow < rhs.flow;
}

bool pathCalculator::operator>(  pathCalculator &rhs)   {
    return rhs < *this;
}

bool pathCalculator::operator<=(  pathCalculator &rhs)   {
    return !(rhs < *this);
}

bool pathCalculator::operator>=(  pathCalculator &rhs)   {
    return !(*this < rhs);
}

pathCalculator::pathCalculator(int flow, const  Spots &origin) : flow(flow), origin(origin){}

pathCalculator::pathCalculator() {}
