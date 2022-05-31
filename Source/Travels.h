//
// Created by frant on 22/05/2022.
//

#ifndef TRAVEL
#define TRAVEL

#include <ostream>

class Travel {
public:
    Travel(int origin, int destination, int capacity, int duration, bool used, bool blocked);

    Travel();

    bool operator==(const Travel &rhs) const;

    bool operator!=(const Travel &rhs) const;

    bool operator<(const Travel &rhs) const;

    bool operator>(const Travel &rhs) const;

    bool operator<=(const Travel &rhs) const;

    bool operator>=(const Travel &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Travel &aTravel);

    int getOrigin() const;

    int getDestination() const;

    int getCapacity() const;

    int getDuration() const;

    bool getUsed() const;

    void sended();

    void reset();

    bool getBlock() const;

    void block();

    void unblock();


private:
    int origin;

    int destination;

    int capacity;

    int duration;

    bool used;

    bool blocked;

};

#endif //TRAVEL
