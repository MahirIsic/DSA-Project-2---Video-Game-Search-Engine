#include <iostream>
#include "heap.h"
#include "driver.h"

using namespace std;

// Run using &".\out\build\x64-Debug\DSAProject2.exe" In the terminal.
// 
// Current State of main.cpp: Loads the CSV file, prints the number of loaded and skipped records, and searches for a game by ID, printing the results.
// Will later have a menu that allows the user to use our functions.

int main() {
    // The heap is created within the driver class.
    Driver driver;

    if (!driver.loadCsv("Data/games.csv")) {
        cout << "Could not open CSV file." << endl;
        return 1;
    }

    cout << "Loaded: " << driver.getLoadedRecords() << endl;
    cout << "Skipped: " << driver.getSkippedRecords() << endl;

    // ID 1030300 is "1030300 - Hollow Knight: Silksong = $15.99"
    vector<GameNode*> results = driver.searchById(1030300);

    for (GameNode* game : results) {
        cout << game->getGameID() << " - " << game->getGameName() << " - $" << game->getPrice() << '\n';
    }

    return 0;
}