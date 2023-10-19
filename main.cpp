#include "ManagementTrips.h"
#include <iostream>
using namespace std;

void deleteTrips(ManagementTrips* mts);
void AddTrip(ManagementTrips* mts);

int main() {
    ManagementTrips mts;
    int option;
    do {
        cout << "Please Select an Option: \n1. Print Trips \n2. Delete Trips \n3. Add Trips \n4. Exit" << endl;
        cin >> option;
        switch (option) {
        case 1:
            cout << mts << endl;
            break;
        case 2:
            deleteTrips(&mts);
            break;
        case 3:
            AddTrip(&mts);
            break;
        case 4:
            cout << "bye bye!" << endl;
            break;
        default:
            cout << "Invalid Option!" << endl;
            break;
        }
    } while (option != 4);

    return 0;
}

void deleteTrips(ManagementTrips* mts) {
    int tripNumber;
    cout << "Enter trip number to delete: ";
    cin >> tripNumber;

    Trip* tripToDelete = new Trip("", Date(0, 0, 0));
    *mts -= tripToDelete;
    delete tripToDelete;
}

void AddTrip(ManagementTrips* mts) {
    int tripNumber, day, month, year;
    string destination;

    cout << "Enter trip number: ";
    cin >> tripNumber;

    cin.ignore(); 
    cout << "Enter destination: ";
    getline(cin, destination);

    cout << "Enter date (day month year): ";
    cin >> day >> month >> year;

    Date tripDate(day, month, year);
    Trip* newTrip = new Trip(destination, tripDate);
    *mts += newTrip;
}
