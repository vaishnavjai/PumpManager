//Made and submitted by: Jaideep, Jarred, Haarith, Ravjot and Ronin
#include "FuelStorage.h"
#include <iostream>

using namespace std;


int main() {
    FuelStorage fuelStorage;

    fuelStorage.insertFuel(95, "Premium", 1000, 2.5);
    fuelStorage.insertFuel(90, "Regular", 2000, 2.0);
    fuelStorage.insertFuel(85, "Diesel", 1500, 1.8);
    fuelStorage.insertFuel(95, "Super", 3000, 2.8);
    fuelStorage.insertFuel(98, "Octane", 750, 3.0);
    cout << "All Fuel Information:\n";
    fuelStorage.printFuel();

    // User Input Section
    int purityToSearch;
    string fuelNameToSearch;

    cout << "Enter desired fuel purity (If you are an employee, enter your 4 digit pin): "; //PIN encryption has not been implemented for the prof's ease of testing, Any combination of 4 integers should work as a PIN.
    cin >> purityToSearch;
    if (purityToSearch >= 1000) {
        cout << "All Fuel Information:\n";
        fuelStorage.printFuel();

        // User Input Section
        int purityToRefill;
        string fuelNameToRefill;

        cout << "Enter desired fuel purity to refill: ";
        cin >> purityToRefill;

        cout << "Enter desired fuel name to refill: ";
        cin >> fuelNameToRefill;

        FuelInfo *foundFuel = fuelStorage.searchFuel(purityToRefill, fuelNameToRefill);
        if (foundFuel != nullptr) {


            // Refill fuel
            double quantityToAdd;
            cout << "Enter quantity to refill (in liters): ";
            cin >> quantityToAdd;

            fuelStorage.refillFuel(purityToRefill, fuelNameToRefill, quantityToAdd);
            // Display updated fuel information after refill
            cout << "\nUpdated Fuel Information:\n";
            fuelStorage.printFuel();
        } else {
            cerr << "\nInvalid Fuel Mix" << endl;
        }

    } else {

        cout << "Enter desired fuel name: ";
        cin >> fuelNameToSearch;

        // Continue with search as before
        FuelInfo *foundFuel = fuelStorage.searchFuel(purityToSearch, fuelNameToSearch);

        if (foundFuel != nullptr) {
            // ... (rest of your code to print fuel info)
            cout << "Fuel found:\n";
            cout << "Name: " << foundFuel->name << "\n";
            cout << "Quantity available: " << foundFuel->quantity << "L\n";
            cout << "Price per litre: $" << foundFuel->pricePerLitre << "\n";
            cout << "\nTo purchase this fuel, Enter P. " << endl;
            char userDecision;
            cin >> userDecision;
            if (userDecision == 'P' || userDecision == 'p') {
                // Purchase fuel
                double quantityToPurchase;
                cout << "Enter quantity to purchase (in liters): ";
                cin >> quantityToPurchase;

                if (fuelStorage.purchaseFuel(purityToSearch, fuelNameToSearch, quantityToPurchase)) {
                    // Display updated fuel information after purchase
                    cout << "\nUpdated Fuel Information:\n";
                    fuelStorage.printFuel();
                }

            }


        } else {
            cerr << "Fuel not found.\n";
        }
    }
}

