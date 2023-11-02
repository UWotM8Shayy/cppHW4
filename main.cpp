#ifndef TRIP_H
#define TRIP_H

#include "date.h"
#include <iostream>
using namespace std;

class Trip
{
private:
    static int tripCount;
    int tripNum;
    char* dest;
    Date date;
    bool ValiDest(const char* dest);

public:
    Trip();
    Trip(const Trip& other);
    ~Trip();
    Trip(const char* dest, const Date& date);

    Trip& operator=(const Trip& other);

    int getTripNum() const;
    const char* getDest() const;
    Date getDate() const;
    void setTripNum(int tripNum);
    void setDest(const char* dest);
    void setDate(const Date& date);
    bool operator==(const Trip& other) const;
    friend ostream& operator<<(ostream& os, const Trip& trip);
    static int getCount();
};

#endif
