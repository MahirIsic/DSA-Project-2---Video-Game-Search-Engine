#pragma once
#include <string>
#include <vector>

using std::vector;
using std::string;

class GameNode
{
    int game_id;
    string game_name;
    float price_in_dollars;
    bool windows_support;
    bool mac_support;
    bool linux_support;
    vector<string> supported_languages;

public:
    GameNode();
    bool operator <(GameNode other);
    bool operator >(GameNode other);
    bool operator <=(GameNode other);
    bool operator >=(GameNode other);

};