#pragma once
#include <string>
#include <unordered_set>
#include <vector>
#include "gameNode.h"

class Driver
{
private:
	std::vector<GameNode> all_games;
	std::vector<GameNode> filtered_games;
	int loaded_records;
	int skipped_records;

	static std::vector<std::string> parseCsvLine(std::string line);
	static std::unordered_set<std::string> parseLanguages(std::string value);
	static bool parseBoolean(std::string value);

public:
	Driver();
	bool loadCsv(std::string filename);

	int getLoadedRecords();
	int getSkippedRecords();

	std::vector<GameNode>& searchByName(std::string name);
	std::vector<GameNode>& searchById(int id);
	std::vector<GameNode>& searchByWindowsSupport(bool windows_support);
	std::vector<GameNode>& searchByMacSupport(bool mac_support);
	std::vector<GameNode>& searchByLinuxSupport(bool linux_support);
	std::vector<GameNode>& searchByPrice(float min_price, float max_price);
	std::vector<GameNode>& searchByLanguageSupport(std::string language);
	std::vector<GameNode>& getFilteredGames();
};