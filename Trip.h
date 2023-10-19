#ifndef TRIP_H
#define TRIP_H

#include "Date.h"
#include <string>

class Trip {
private:
    static int counter;
    int tripNumber;
    std::string destination;
    Date date;

public:
    
    Trip();
    Trip(const std::string& destination, const Date& date);

    static int getCounter();
    
    int getTripNumber() const;
    std::string getDestination() const;
    Date getDate() const;

    //void setTripNumber(int tripNumber);
    void setDestination(const std::string& destination);
    void setDate(const Date& date);

    //void printTrip() const;

    friend std::ostream& operator<<(std::ostream& os, const Trip& trip);
    
    Trip& operator=(const Trip& other);

    Trip(const Trip& other);

    ~Trip();
};

#endif 
