#include "Trip.h"
#include <iostream>
#include <cctype>

int Trip::counter = 1;

Trip::Trip() : tripNumber(counter++), destination(""), date() {}

Trip::Trip(const std::string& destination, const Date& date)
    : tripNumber(counter++), destination(destination), date(date) {}


int Trip::getTripNumber() const {
    return tripNumber;
}

std::string Trip::getDestination() const {
    return destination;
}

Date Trip::getDate() const {
    return date;
}

int Trip::getCounter() {
    return counter;
}

//void Trip::setTripNumber(int tripNumber) {
//    if (tripNumber > 0) {
//        this->tripNumber = tripNumber;
//    }
//}

void Trip::setDestination(const std::string& destination) {
    bool isOnlyLetters = true;
    for (char ch : destination) {
        if (!isalpha(ch)) {
            isOnlyLetters = false;
            break;
        }
    }

    if (isOnlyLetters) {
        this->destination = destination;
    }
    else {
        std::cout << "Error: Destination can only contain letters." << std::endl;
    }
}

void Trip::setDate(const Date& date) {
    this->date = date;
}


//void Trip::printTrip() const {
//    std::cout << "Trip Number: " << tripNumber << std::endl;
//    std::cout << "Destination: " << destination << std::endl;
//    std::cout << "Date: ";
//    date.printDate();
//}


Trip& Trip::operator=(const Trip& other) {
    if (this != &other) {
        tripNumber = other.tripNumber;
        destination = other.destination;
        date = other.date;
    }
    return *this;
}


Trip::Trip(const Trip& other)
    : tripNumber(counter++), destination(other.destination), date(other.date) {}

Trip::~Trip() 
{
  
}

std::ostream& operator<<(std::ostream& os, const Trip& trip) {
    os << "Trip Number: " << trip.tripNumber << std::endl;
    os << "Destination: " << trip.destination << std::endl;
    os << "Date: " << trip.date;
    return os;
}
