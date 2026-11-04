#include "driver.h"
#include <fstream>
#include <stdexcept>

using namespace std;

// Initializes the record counters to zero.
// The records are not necessary for the project, but just for the sake of testing and debugging, they are included to provide feedback on how many records were successfully loaded and how many were skipped due to errors.
Driver::Driver() : loaded_records(0), skipped_records(0) {}

// Scans the row character by character, splitting on unquoted commas and treating doubled quotes as escaped quotes.
vector<string> Driver::parseCsvLine(string line) {
	vector<string> fields;
	string field;
	bool inside_quotes = false;

	for (size_t i = 0; i < line.size(); ++i) {
		char c = line[i];
		if (c == '"') {
			if (inside_quotes && i + 1 < line.size() && line[i + 1] == '"') {
				field += '"';
				++i;
			} 
			else {
				inside_quotes = !inside_quotes;
			}
		} 
		else if (c == ',' && !inside_quotes) {
			fields.push_back(field);
			field.clear();
		} 
		else {
			field += c;
		}
	}

	fields.push_back(field);
	return fields;
}

// Parses a bracketed, comma-separated language value into a set of languages.
unordered_set<string> Driver::parseLanguages(string value) {
	unordered_set<string> languages;
	string language;

	for (char c : value) {
		if (c == '[' || c == ']' || c == '\'') {
			continue;
		}
		if (c == ',') {
			if (!language.empty()) {
				languages.insert(language);
				language.clear();
			}
		} else if (c != ' ' || !language.empty()) {
			language += c;
		}
	}

	if (!language.empty()) {
		languages.insert(language);
	}
	return languages;
}

// Converts contextual values into a boolean.
bool Driver::parseBoolean(string value) {
	return value == "True" || value == "true" || value == "1";
}

// Main function that loads game records into the all_games vector from a CSV file.
bool Driver::loadCsv(string filename) {
	ifstream input(filename);
	if (!input.is_open()) {
		return false;
	}

	loaded_records = 0;
	skipped_records = 0;
	all_games.clear();
	filtered_games.clear();

	string line;
	if (!getline(input, line)) {
		return true;
	}

	// Read each line of the CSV file, parse it, and insert it into the vector.
	while (getline(input, line)) {
		if (line.empty()) {
			continue;
		}

		vector<string> fields = parseCsvLine(line);
		if (fields.size() <= 19) {
			++skipped_records;
			continue;
		}

		try {
			int id = stoi(fields[0]);
			string name = fields[1];
			float price = stof(fields[6]);
			bool windows_support = parseBoolean(fields[17]);
			bool mac_support = parseBoolean(fields[18]);
			bool linux_support = parseBoolean(fields[19]);
			unordered_set<string> supported_languages = parseLanguages(fields[10]);

			all_games.emplace_back(id, name, price, windows_support, mac_support, linux_support, supported_languages);
			++loaded_records;
		}
		catch (invalid_argument&) {
			++skipped_records;
		}
		catch (out_of_range&) {
			++skipped_records;
		}
	}
	return true;
}

int Driver::getLoadedRecords() { return loaded_records; }

int Driver::getSkippedRecords() { return skipped_records; }

vector<GameNode>& Driver::searchByName(string name) {
	filtered_games.clear();
	for (GameNode& game : all_games) {
		if (game.getGameName() == name) {
			filtered_games.push_back(game);
		}
	}
	return filtered_games;
}

vector<GameNode>& Driver::searchById(int id) {
	filtered_games.clear();
	for (GameNode& game : all_games) {
		if (game.getGameID() == id) {
			filtered_games.push_back(game);
		}
	}
	return filtered_games;
}

vector<GameNode>& Driver::searchByWindowsSupport(bool windows_support) {
	filtered_games.clear();
	for (GameNode& game : all_games) {
		if (game.getWindowsSupport() == windows_support) {
			filtered_games.push_back(game);
		}
	}
	return filtered_games;
}

vector<GameNode>& Driver::searchByMacSupport(bool mac_support) {
	filtered_games.clear();
	for (GameNode& game : all_games) {
		if (game.getMacSupport() == mac_support) {
			filtered_games.push_back(game);
		}
	}
	return filtered_games;
}

vector<GameNode>& Driver::searchByLinuxSupport(bool linux_support) {
	filtered_games.clear();
	for (GameNode& game : all_games) {
		if (game.getLinuxSupport() == linux_support) {
			filtered_games.push_back(game);
		}
	}
	return filtered_games;
}

vector<GameNode>& Driver::searchByPrice(float min_price, float max_price) {
	filtered_games.clear();
	for (GameNode& game : all_games) {
		if (game.getPrice() >= min_price && game.getPrice() <= max_price) {
			filtered_games.push_back(game);
		}
	}
	return filtered_games;
}

vector<GameNode>& Driver::searchByLanguageSupport(string language) {
	filtered_games.clear();
	for (GameNode& game : all_games) {
		if (game.getSupportedLanguages().count(language) != 0) {
			filtered_games.push_back(game);
		}
	}
	return filtered_games;
}

vector<GameNode>& Driver::getFilteredGames() {
	return filtered_games;
}
