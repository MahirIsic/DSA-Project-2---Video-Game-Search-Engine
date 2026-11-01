#pragma once
#include <string>
#include <vector>
#include <unordered_set>

using std::vector;
using std::string;
using std::unordered_set;

class GameNode
{
    int game_id;
    string game_name;
    float price_in_dollars;
    bool windows_support;
    bool mac_support;
    bool linux_support;
    unordered_set<string> supported_languages;

public:
    GameNode();
    GameNode(int input_id,string input_name,float input_price,bool input_windows_support,bool input_mac_support,bool input_linux_support,unordered_set<string> input_supported_languages);
    int getGameID();
    float getPrice();
    bool getWindowsSupport();
    bool getMacSupport();
    bool getLinuxSupport();
    unordered_set<string> getSupportedLanguages();
    string getGameName();
    // bool operator <(GameNode other);
    // bool operator >(GameNode other);
    bool operator <=(GameNode other);
    // bool operator >=(GameNode other);

};