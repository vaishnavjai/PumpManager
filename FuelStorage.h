#ifndef FUELSTORAGE_H
#define FUELSTORAGE_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Fuel information
struct FuelInfo {
    string name;
    double quantity;
    double pricePerLitre;
};

// Hash table class for storing information for each fuel
class FuelStorage{
private:
    vector<vector<FuelInfo>> hashTable; // Vector hash table
public:
    // Constructor initializes hash table
    FuelStorage(){
        hashTable.resize(100); // Hash table size is 100 due to the key being represented by a percentage
    }

    // Hash function based on purity percentage
    int hashFunction(int purity){
        return (purity) % 100;
    }

    // Adding fuel information to the hash table
    void insertFuel(int purity, const string& name, double quantity, double pricePerLitre){
        FuelInfo fuel = {name, quantity, pricePerLitre}; // FuelInfo struct
        int index = hashFunction(purity);
        hashTable[index].push_back(fuel);
    }

    // Searches for requested fuel based on purity
    FuelInfo* searchFuel(int purity, const string& name){
        int index = hashFunction(purity);
        for (auto& fuel : hashTable[index]){ // Iterate through the vector at the given purity key and check names to match
            if (fuel.name == name){
                return &fuel;
            }
        }
        return nullptr;
    }

    // Prints fuel all fuel information
    void printFuel(){
        for (int i = 0; i < 100; i++){
            for (const auto& fuel : hashTable[i]){
                cout << "Purity: " << i << "%\n" << "Name: " << fuel.name << "\nQuantity available: " << fuel.quantity << "L\n" << "Price per litre: $" << fuel.pricePerLitre << "\n\n\n";
            }
        }
    }

    // Purchase fuel
    bool purchaseFuel(int purity, const string& name, double quantityToPurchase){
        FuelInfo* fuel = searchFuel(purity, name);
        if (fuel != nullptr && fuel->quantity >= quantityToPurchase){
            fuel->quantity -= quantityToPurchase;
            cout << "Purchase successful. You bought " << quantityToPurchase << "L of " << name << " with purity " << purity << "%.\n";
            return true;
        }
        else{
            cout << "Unable to purchase. Either the fuel is not available or the quantity requested exceeds availability.\n";
            return false;
        }
    }

    // Refill fuel
    void refillFuel(int purity, const string& name, double quantityToAdd){
        FuelInfo* fuel = searchFuel(purity, name);
        if (fuel != nullptr){
            fuel->quantity += quantityToAdd;
            cout << "Refill successful. Added " << quantityToAdd << "L of " << name << " with purity " << purity << "%.\n";
        }
        else{
            // If the fuel doesn't exist, add it
            insertFuel(purity, name, quantityToAdd, 0.0);
            cout << "Refill successful. Added " << quantityToAdd << "L of new fuel: " << name << " with purity " << purity << "%.\n";
        }
    }
};

#endif // FUELSTORAGE_H
