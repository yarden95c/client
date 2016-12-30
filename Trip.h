//
// Created by moran on 03/12/16.
//

#ifndef TEST1_TRIP_H
#define TEST1_TRIP_H


#include <list>
#include "Point.h"
#include "Driver.h"

using namespace std;

/**
 * class trip.
 */
class Trip {
private:
    int tripId;
    Point *start;
    Point *end;
    int passengersNum;
    double tariff;
    Driver *driver;
    bool isPending;
public:
    Trip(int id, Point *start1, Point *end1, int numOfPassengers,
         double tariff1);

    bool getIsPending();

    int getTripId();

    Point *getStartPoint();

    Point *getEndPoint();

    int getPassengersNum();

    double getTariff();

    void setDriver(Driver *driver1);

    void setPending(bool pending);

    Driver *getDriver();

    friend bool operator==(Trip trip1, Trip trip2);

    friend bool operator!=(Trip trip1, Trip trip2);

    ~Trip();
};

#endif //TEST1_TRIP_H