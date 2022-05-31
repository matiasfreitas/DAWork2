//
// Created by Matias Freitas Guimarães on 31/05/2022.
//

#ifndef DAWORK2_SPOTS_H
#define DAWORK2_SPOTS_H

#include <set>
#include "Travel.h"

class Spots {
public:
    Spots(int location);
    void addPath(Travel newPath);

    bool operator==(const Spots &rhs) const;

    bool operator!=(const Spots &rhs) const;

    int getLocation() const;

    bool operator<(const Spots &rhs) const;

    bool operator>(const Spots &rhs) const;

    bool operator<=(const Spots &rhs) const;

    bool operator>=(const Spots &rhs) const;

    const std::set<Travel> &getPaths() const;

private:
    int location;
    std::set<Travel> paths;
};


#endif //DAWORK2_SPOTS_H
