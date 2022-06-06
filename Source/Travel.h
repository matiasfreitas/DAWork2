//
// Created by frant on 22/05/2022.
//

#ifndef TRAVEL
#define TRAVEL

#include <ostream>

class Travel {
public:
    Travel(int origin, int destination, int capacity, int duration);

    Travel();

    bool operator==(const Travel &rhs) const;

    bool operator!=(const Travel &rhs) const;

    bool operator<(const Travel &rhs) const;

    bool operator>(const Travel &rhs) const;

    bool operator<=(const Travel &rhs) const;

    bool operator>=(const Travel &rhs) const;

    Travel& operator=(Travel other){
        this->origin = other.origin;
        this->destination = other.destination;
        this->visited = other.visited;
        this->capacity = other.capacity;
        this->duration = other.duration;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Travel &aTravel);

    int getOrigin() const;

    int getDestination() const;

    int getCapacity() const;

    int getDuration() const;

    void setVisited(bool value);

    bool getVisited() const;

    int getTransportados() const;

    void setTransportados(int value);

    bool isViablePathTo(int cap);

private:
    int origin;

    int destination;

    int capacity;

    int duration;

    bool visited;

    int transportados;
};

#endif //TRAVEL
