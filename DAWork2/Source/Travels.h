//
// Created by frant on 22/05/2022.
//
#include <ostream>
#ifndef DAWork2_TRAVELS_H
#define DAWork2_TRAVELS_H


class Travel {
public:
    Travel(int origin, int destination, int capacity, int duration);
    Travel();

    int getorigin() const;

    int getdestination() const;

    int getcapacity() const;

    int getduration() const;

    bool operator==(const Travel &rhs) const;

    bool operator!=(const Travel &rhs) const;

    bool operator<(const Travel &rhs) const;

    bool operator>(const Travel &rhs) const;

    bool operator<=(const Travel &rhs) const;

    bool operator>=(const Travel &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Travel &aTravel);


private:
    int origin;

    int destination;

    int capacity;

    int duration;

};

#endif //DAWork2_TRAVELS_H
