#ifndef MANAGEMENT_TRIPS_H
#define MANAGEMENT_TRIPS_H

#include "trip.h"
#include <iostream>

class ManagementTrips {
    private:
        Trip** trips;
        int index;
    public:
    ManagementTrips();
    ManagementTrips(const ManagementTrips& other);
    ~ManagementTrips();
    ManagementTrips& operator=(const ManagementTrips& other);
    ManagementTrips& operator+=(Trip& trip);
    ManagementTrips& operator-=(Trip& trip);
    friend ostream& operator<<(ostream& os,const ManagementTrips& managment);


};

#endif
