//
// Created by Matias Freitas Guimarães on 31/05/2022.
//

#include "Spots.h"

Spots::Spots(int location): location(location), paths({}) {

}

void Spots::addPath(Travel newPath){
    paths.insert(newPath);

}

bool Spots::operator==(const Spots &rhs) const {
    return location == rhs.location;
}

bool Spots::operator!=(const Spots &rhs) const {
    return !(rhs == *this);
}

int Spots::getLocation() const {
    return location;
}

bool Spots::operator<(const Spots &rhs) const {
    return location < rhs.location;
}

bool Spots::operator>(const Spots &rhs) const {
    return rhs < *this;
}

bool Spots::operator<=(const Spots &rhs) const {
    return !(rhs < *this);
}

bool Spots::operator>=(const Spots &rhs) const {
    return !(*this < rhs);
}

