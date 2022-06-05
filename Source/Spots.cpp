//
// Created by Matias Freitas Guimarães on 31/05/2022.
//

#include "Spots.h"

Spots::Spots(int location): location(location), paths({}), visited(false) {

}

void Spots::addPath(Travel &newPath){
    paths.push_back(newPath);
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

std::vector<Travel> Spots::getPaths(){
    return paths;
}

void Spots::setVisited(bool visited) {
    Spots::visited = visited;
}

bool Spots::getVisited() {
    return visited;
}
Spots::Spots() {

}


