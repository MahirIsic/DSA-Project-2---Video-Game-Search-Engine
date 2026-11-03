#include "driver.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;

// Initializes the record counters to zero.
// The records are not necessary for the project, but just for the sake of testing and debugging, they are included to provide feedback on how many records were successfully loaded and how many were skipped due to errors.
Driver::Driver() : loaded_records(0), skipped_records(0) {}

// Scans the row character by character, splitting on unquoted commas and treating doubled quotes as escaped quotes.
vector<string> Driver::parseCsvLine(const string& line) {
	vector<string> fields;
	string field;
	bool inside_quotes = false;

	for (size_t i = 0; i < line.size(); ++i) {
		char c = line[i];
		if (c == '"') {
			if (inside_quotes && i + 1 < line.size() && line[i + 1] == '"') {
				field += '"';
				++i;
			} else {
				inside_quotes = !inside_quotes;
			}
		} else if (c == ',' && !inside_quotes) {
			fields.push_back(field);
			field.clear();
		} else {
			field += c;
		}
	}

	fields.push_back(field);
	return fields;
}

// Parses a bracketed, comma-separated language value into a set of languages.
unordered_set<string> Driver::parseLanguages(const string& value) {
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

// Converts the supported textual and numeric true values into a boolean.
bool Driver::parseBoolean(const string& value) {
	return value == "True" || value == "true" || value == "1";
}

// Loads game records from a CSV file onto the heap and tracks how many rows load or are skipped.
bool Driver::loadCsv(const string& filename) {
	ifstream input(filename);
	if (!input.is_open()) {
		return false;
	}

	loaded_records = 0;
	skipped_records = 0;

	string line;
	if (!getline(input, line)) {
		return true;
	}

	// Read each line of the CSV file, parse it, and insert it into the heap.
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
			game_heap.insert(
				stoi(fields[0]),
				fields[1],
				stof(fields[6]),
				parseBoolean(fields[17]),
				parseBoolean(fields[18]),
				parseBoolean(fields[19]),
				parseLanguages(fields[10]));
			++loaded_records;
		} catch (const invalid_argument&) {
			++skipped_records;
		} catch (const out_of_range&) {
			++skipped_records;
		}
	}

	return true;
}

int Driver::getLoadedRecords() const { return loaded_records; }

int Driver::getSkippedRecords() const { return skipped_records; }

vector<GameNode*> Driver::searchByName(const string& name) {
	Heap matches = game_heap.searchByName(name);
	auto sort_start = chrono::steady_clock::now();
	vector<GameNode*> results = game_heap.sortHeap(matches);
	auto sort_end = chrono::steady_clock::now();
	cout << "Sort time: "
		 << chrono::duration_cast<chrono::microseconds>(sort_end - sort_start).count()
		 << " microseconds\n";
	return results;
}

vector<GameNode*> Driver::searchById(int id) {
	Heap matches = game_heap.searchByID(id);
	auto sort_start = chrono::steady_clock::now();
	vector<GameNode*> results = game_heap.sortHeap(matches);
	auto sort_end = chrono::steady_clock::now();
	cout << "Sort time: "
		 << chrono::duration_cast<chrono::microseconds>(sort_end - sort_start).count()
		 << " microseconds\n";
	return results;
}

vector<GameNode*> Driver::searchByWindowsSupport(bool windows_support) {
	Heap matches = game_heap.searchByWindowsSupport(windows_support);
	auto sort_start = chrono::steady_clock::now();
	vector<GameNode*> results = game_heap.sortHeap(matches);
	auto sort_end = chrono::steady_clock::now();
	cout << "Sort time: "
		 << chrono::duration_cast<chrono::microseconds>(sort_end - sort_start).count()
		 << " microseconds\n";
	return results;
}

vector<GameNode*> Driver::searchByMacSupport(bool mac_support) {
	Heap matches = game_heap.searchByMacSupport(mac_support);
	auto sort_start = chrono::steady_clock::now();
	vector<GameNode*> results = game_heap.sortHeap(matches);
	auto sort_end = chrono::steady_clock::now();
	cout << "Sort time: "
		 << chrono::duration_cast<chrono::microseconds>(sort_end - sort_start).count()
		 << " microseconds\n";
	return results;
}

vector<GameNode*> Driver::searchByLinuxSupport(bool linux_support) {
	Heap matches = game_heap.searchByLinuxSupport(linux_support);
	auto sort_start = chrono::steady_clock::now();
	vector<GameNode*> results = game_heap.sortHeap(matches);
	auto sort_end = chrono::steady_clock::now();
	cout << "Sort time: "
		 << chrono::duration_cast<chrono::microseconds>(sort_end - sort_start).count()
		 << " microseconds\n";
	return results;
}

vector<GameNode*> Driver::searchByPrice(float min_price, float max_price) {
	Heap matches = game_heap.searchByPrice(min_price, max_price);
	auto sort_start = chrono::steady_clock::now();
	vector<GameNode*> results = game_heap.sortHeap(matches);
	auto sort_end = chrono::steady_clock::now();
	cout << "Sort time: "
		 << chrono::duration_cast<chrono::microseconds>(sort_end - sort_start).count()
		 << " microseconds\n";
	return results;
}

vector<GameNode*> Driver::searchByLanguageSupport(const string& language) {
	Heap matches = game_heap.searchByLanguageSupport(language);
	auto sort_start = chrono::steady_clock::now();
	vector<GameNode*> results = game_heap.sortHeap(matches);
	auto sort_end = chrono::steady_clock::now();
	cout << "Sort time: "
		 << chrono::duration_cast<chrono::microseconds>(sort_end - sort_start).count()
		 << " microseconds\n";
	return results;
}
