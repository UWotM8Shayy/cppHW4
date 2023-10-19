

#include "ManagementTrips.h"
#include <iostream>


ManagementTrips::ManagementTrips() : trips(nullptr), index(0) {}

ManagementTrips::ManagementTrips(const ManagementTrips& other) : index(other.index) {
    trips = new Trip * [other.index];
    for (int i = 0; i < other.index; ++i) {
        trips[i] = new Trip(*(other.trips[i])); 
    }
}


ManagementTrips::~ManagementTrips() {
    if (trips != nullptr) {
        for (int i = 0; i < index; ++i) {
            delete trips[i]; 
        }
        delete[] trips; 
    }
}

ManagementTrips& ManagementTrips::operator=(const ManagementTrips& other) {
    if (this != &other) {
        if (trips != nullptr) {
            for (int i = 0; i < index; ++i) {
                delete trips[i];
            }
            delete[] trips;
        }

        index = other.index;
        trips = new Trip * [index];
        for (int i = 0; i < index; ++i) {
            trips[i] = new Trip(*(other.trips[i])); 
        }
    }
    return *this;
}


ManagementTrips& ManagementTrips::operator+=(Trip* newTrip) {
    if (newTrip != nullptr) {
       
        Trip** newTrips = new Trip * [index + 1];
        for (int i = 0; i < index; ++i) {
            newTrips[i] = trips[i];
        }
        newTrips[index] = newTrip; 
        ++index;

       
        delete[] trips;
        trips = newTrips;
    }
    return *this;
}


ManagementTrips& ManagementTrips::operator-=(const Trip* tripToRemove) {
    if (tripToRemove != nullptr) {
        int removalCount = 0;
        for (int i = 0; i < index; ++i) {
            const Date& tripDate = trips[i]->getDate();
            const Date& removeDate = tripToRemove->getDate();
            if (tripDate.getDay() == removeDate.getDay() &&
                tripDate.getMonth() == removeDate.getMonth() &&
                tripDate.getYear() == removeDate.getYear()) {

                delete trips[i];
                ++removalCount;
                trips[i] = nullptr;
            }
        }

        
        Trip** newTrips = new Trip * [index - removalCount];
        int newIndex = 0;
        for (int i = 0; i < index; ++i) {
            if (trips[i] != nullptr) {
                newTrips[newIndex++] = trips[i];
            }
        }

        
        delete[] trips;
        trips = newTrips;
        index = newIndex;
    }
    return *this;
}




std::ostream& operator<<(std::ostream& os, const ManagementTrips& tripsList) {
    if (tripsList.index == 0) {
        os << "Trip List Empty";
    }
    else {
        for (int i = 0; i < tripsList.index; ++i) {
            os << "Trip " << i + 1 << ":" << std::endl;
            os << *(tripsList.trips[i]); 
            os << std::endl;
        }
    }
    return os;
}
