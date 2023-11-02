#include "ManagmentTrips.h"
using namespace std;
ManagementTrips::ManagementTrips() : trips(nullptr) , index(0)
{

}
ManagementTrips::ManagementTrips(const ManagementTrips& other) {
    index = other.index;
    trips = new Trip*[index];
    for(int i=0;i< index; i++)
    {
        trips[i] = new Trip(*other.trips[i]);
    }
}
ManagementTrips::~ManagementTrips()
{
     for(int i=0;i< index; i++)
    {
        delete trips[i];
    }
    delete[] trips;
}
ManagementTrips& ManagementTrips::operator=(const ManagementTrips& other) {
    if (this != &other) {
        for (int i = 0; i < index; ++i) {
            delete trips[i];
        }
        delete[] trips;

        index = other.index;
        trips = new Trip*[index];
        for (int i = 0; i < index; ++i) {
            trips[i] = new Trip(*other.trips[i]);
        }
    }
    return *this;
}

ManagementTrips& ManagementTrips::operator+=(Trip& trip) 
{
    Trip** newTrips = new Trip*[index + 1];
    for(int i=0; i < index; ++i)
    {
        newTrips[i] = trips[i];
    }
    newTrips[index] = &trip;
    delete[] trips;
    trips = newTrips;
    index++;
    return *this;
}

ManagementTrips& ManagementTrips::operator-=(Trip& trip) 
{
    int originalIndex = index;
    int currentIndex = 0;  
    Trip** tempTrips = new Trip*[index];  
    for (int i = 0; i < originalIndex; ++i) 
    {
        if (!(trips[i]->getDate() == trip.getDate())) 
            tempTrips[currentIndex++] = trips[i];
        else 
        {
            delete trips[i]; 
        }
    }

 
    delete[] trips;
    trips = tempTrips;
    index = currentIndex;  

    return *this;
}


ostream& operator<<(std::ostream& os, const ManagementTrips& management) 
{
    if (management.index == 0) 
        os << "The tours list is empty." << endl;
     else 
     {
        for (int i = 0; i < management.index; ++i) 
        {
            os << *management.trips[i] << endl;  
        }
    }
    return os;
}
