#pragma once
#include <string>
#include <vector>
#include "Heap.h"

class Driver
{
private:
	// Driver includes the heap

	Heap game_heap;
	int loaded_records;
	int skipped_records;

	static std::vector<std::string> parseCsvLine(const std::string& line);
	static std::unordered_set<std::string> parseLanguages(const std::string& value);
	static bool parseBoolean(const std::string& value);

public:
	Driver();
	bool loadCsv(const std::string& filename);

	int getLoadedRecords() const;
	int getSkippedRecords() const;

	std::vector<GameNode*> searchByName(const std::string& name);
	std::vector<GameNode*> searchById(int id);
	std::vector<GameNode*> searchByWindowsSupport(bool windows_support);
	std::vector<GameNode*> searchByMacSupport(bool mac_support);
	std::vector<GameNode*> searchByLinuxSupport(bool linux_support);
	std::vector<GameNode*> searchByPrice(float min_price, float max_price);
	std::vector<GameNode*> searchByLanguageSupport(const std::string& language);
};