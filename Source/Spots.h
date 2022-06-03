//
// Created by Matias Freitas Guimarães on 31/05/2022.
//

#ifndef DAWORK2_SPOTS_H
#define DAWORK2_SPOTS_H

#include <set>
#include <vector>
#include "Travel.h"

class Spots {
public:
    Spots();
    Spots(int location);
    void addPath(Travel &newPath);

    bool operator==(const Spots &rhs) const;

    bool operator!=(const Spots &rhs) const;

    int getLocation() const;

    bool operator<(const Spots &rhs) const;

    bool operator>(const Spots &rhs) const;

    bool operator<=(const Spots &rhs) const;
    Spots& operator=(Spots other){
        this->paths = other.paths;
        this->location = other.location;
        this->visited = other.visited;
        return *this;
    }
    bool operator>=(const Spots &rhs) const;

    std::vector<Travel> getPaths();

    void setVisited(bool visited);

    bool getVisited();


private:
    int location;
    std::vector<Travel> paths;
    bool visited;
};


#endif //DAWORK2_SPOTS_H
