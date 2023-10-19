#ifndef MANAGEMENTTRIPS_H
#define MANAGEMENTTRIPS_H

#include "Trip.h"


class ManagementTrips
{
private:
    Trip** trips; 
    int index; 

public:
    ManagementTrips();
    ManagementTrips(const ManagementTrips& other);

    
    ~ManagementTrips();

    
    ManagementTrips& operator=(const ManagementTrips& other);
    ManagementTrips& operator+=(Trip* newTrip);
    ManagementTrips& operator-=(const Trip* tripToRemove);
    friend std::ostream& operator<<(std::ostream& os, const ManagementTrips& tripsList);

};

#endif 
