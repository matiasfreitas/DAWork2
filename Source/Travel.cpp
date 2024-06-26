//
// Created by frant on 22/05/2022.
//

#include "Travel.h"
#include "Spots.h"

Travel::Travel(int origin, int destination, int capacity, int duration) : origin(origin), destination(destination),
                                                                         capacity(capacity), duration(duration), visited(false){}

Travel::Travel() {}


/**
 * This override operator return true if volume, weight, payment and duration is equal.
 * @param rhs other package to compare
 */
bool Travel::operator==(const Travel &rhs) const {
    return origin == rhs.origin &&
           destination == rhs.destination &&
           capacity == rhs.capacity &&
           duration == rhs.duration;
}

/**
 * This override operator return true if volume, weight, payment or duration is unequal.
 * @param rhs other package to compare
 */
bool Travel::operator!=(const Travel &rhs) const {
    return !(rhs == *this);
}

/**
 * This override operator > return true if that instance is more light and after volume than rhs
 * @param rhs other package to compare
 */
bool Travel::operator<(const Travel &rhs) const {
    if (destination < rhs.destination)
        return true;
    if (rhs.destination < destination)
        return false;
    return origin< rhs.origin;
}

/**
 * This override operator < return tru if that instance os more heavy and after volume than rhs
 * @param rhs other package to compare
 */
bool Travel::operator>(const Travel &rhs) const {
    return rhs < *this;
}

/**
 * This override operator <= return true if that instance is more light and after volume or equal than rhs
 * @param rhs other package to compare
 */
bool Travel::operator<=(const Travel &rhs) const {
    return !(rhs < *this);
}

/**
 * This override operator >= return true if that instance is more heavy and after volume or equal than rhs
 * @param rhs other package to compare
 */
bool Travel::operator>=(const Travel &rhs) const {
    return !(*this < rhs);
}
/**
 * This override operator extractor operator to out information about this object
 * @param os where is going the output
 */
std::ostream &operator<<(std::ostream &os, const Travel &aTravel) {
    os << "origin: " << aTravel.origin << " destination: " << aTravel.destination << " capacity: " << aTravel.capacity
       << " duration: " << aTravel.duration;
    return os;
}



int Travel::getOrigin() const {
    return origin;
}

int Travel::getDestination() const {
    return destination;
}

int Travel::getCapacity() const {
    return capacity;
}

int Travel::getDuration() const {
    return duration;
}

bool Travel::getVisited() const{
    return visited;
}

void Travel::setVisited(bool value) {
    Travel::visited = value;
}

bool Travel::isViablePathTo(int cap) {
    return !this->getVisited() && this->getCapacity() >= cap;
}
