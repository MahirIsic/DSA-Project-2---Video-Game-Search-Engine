#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "driver.h"

using namespace std;

namespace {
void printResults(vector<GameNode>& results, bool show_details) {
    if (results.empty()) {
        // Handle no matches before attempting to display game records.
        cout << "No games matched your search.\n";
        return;
    }

    cout << "Found " << results.size() << " game(s):\n";
    if (!show_details) {
        for (size_t i = 0; i < results.size(); ++i) {
            if (i > 0) {
                cout << ", ";
            }
            cout << results[i].getGameName();
        }
        cout << '\n';
        return;
    }

	// Detailed representation if show_details is true.
    for (GameNode& game : results) {
        cout << "ID: " << game.getGameID()
             << " | Name: " << game.getGameName()
             << " | Price: $" << fixed << setprecision(2) << game.getPrice() << defaultfloat
             << " | Windows: " << (game.getWindowsSupport() ? "Yes" : "No")
             << " | Mac: " << (game.getMacSupport() ? "Yes" : "No")
             << " | Linux: " << (game.getLinuxSupport() ? "Yes" : "No")
             << " | Languages: ";

        bool first_language = true;
        for (const string& language : game.getSupportedLanguages()) {
            if (!first_language) {
                cout << ", ";
            }
            cout << language;
            first_language = false;
        }
        cout << '\n';
    }
}

void searchMenu(Driver& driver) {
    while (true) {
        cout << "\n================================\n"
         << "Search Games\n"
         << "1. Exact name\n"
         << "2. ID\n"
         << "3. Windows support\n"
         << "4. Mac support\n"
         << "5. Linux support\n"
         << "6. Price range\n"
         << "7. Supported language\n"
         << "0. Back to main menu\n"
         << "================================\n";

        int choice;
        cout << "Choose a search option: ";
        if (!(cin >> choice)) {
            if (cin.eof()) {
                return;
            }
            cin.clear();
            string invalid_input;
            getline(cin, invalid_input);
            cout << "Invalid input. Enter a search menu number.\n";
            continue;
        }
        if (choice == 0) {
            // Return to the top-level menu without exiting the whole application.
            return;
        }

        vector<GameNode>* results = nullptr;
		bool show_details = false; // Whether only names are printed vs full details of each game.
        string text;
        int id;
        int support_choice;
        float min_price;
        float max_price;

        switch (choice) {
        case 1:
            cout << "Enter the exact game name (case-sensitive): ";
            // Removes whitespace
            cin >> ws;
            getline(cin, text);
            results = &driver.searchByName(text);
            show_details = true;
            break;
        case 2:
            cout << "Enter the game ID: ";
            cin >> id;
            results = &driver.searchById(id);
            show_details = true;
            break;
        case 3:
            cout << "Find games that support Windows? (1 = yes, 0 = no): ";
            cin >> support_choice;
            results = &driver.searchByWindowsSupport(support_choice == 1);
            break;
        case 4:
            cout << "Find games that support Mac? (1 = yes, 0 = no): ";
            cin >> support_choice;
            results = &driver.searchByMacSupport(support_choice == 1);
            break;
        case 5:
            cout << "Find games that support Linux? (1 = yes, 0 = no): ";
            cin >> support_choice;
            results = &driver.searchByLinuxSupport(support_choice == 1);
            break;
        case 6:
            cout << "Enter minimum price: $";
            cin >> min_price;
            cout << "Enter maximum price: $";
            cin >> max_price;
            results = &driver.searchByPrice(min_price, max_price);
            break;
        case 7:
            cout << "Enter the exact supported language (case-sensitive): ";
            cin >> ws;
            getline(cin, text);
            results = &driver.searchByLanguageSupport(text);
            break;
        default:
            // Ignore unsupported menu numbers and redisplay the search choices.
            cout << "Invalid search option.\n";
            continue;
        }

        printResults(*results, show_details);
    }
}
}

int main() {
    // Driver is created, and values are extracted from the CSV file.
    Driver driver;
    cout << "Extracting Values..." << endl;
    if (!driver.loadCsv("Data/games.csv")) {
        // Do not offer searches against an empty, unloaded dataset.
        cout << "Could not open CSV file." << endl;
        return 1;
    }

    cout << "Values extracted successfully." << endl;


    // Initial menu starts to run
    while (true) {
        cout << "\n================================\n"
            << "Video Game Search Engine\n"
            << "1. Search / Filter games\n"
            << "2. Sort filtered games\n"
            << "3. Show load statistics\n"
            << "4. Display filtered game names\n"
            << "0. Exit\n"
            << "================================\n";

        int choice;
        cout << "Choose an option: ";
        if (!(cin >> choice)) {
            if (cin.eof()) {
                break;
            }
            cin.clear();
            string invalid_input;
            getline(cin, invalid_input);
            cout << "Invalid input. Enter a menu number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            searchMenu(driver);
            break;
        case 2:
            cout << "Sort options are not implemented yet.\n";
            break;
        case 3:
            cout << "Loaded: " << driver.getLoadedRecords() << '\n'
                 << "Skipped: " << driver.getSkippedRecords() << '\n';
            break;
        case 4: {
            const vector<GameNode>& filtered_games = driver.getFilteredGames();
            if (filtered_games.empty()) {
                // Avoid showing an empty list when no filter has produced matches.
                cout << "No filtered games are available. Search or filter first.\n";
                break;
            }

            cout << "Filtered game names (" << filtered_games.size() << "): ";
            for (size_t i = 0; i < filtered_games.size(); ++i) {
                if (i > 0) {
                    cout << ", ";
                }
                cout << filtered_games[i].getGameName();
            }
            cout << '\n';
            break;
        }
        case 0:
            cout << "Exiting.\n";
            return 0;
        default:
            // Keep unexpected selections from runnning.
            cout << "Invalid option. Choose one of the listed numbers.\n";
            break;
        }
    }

    return 0;
}