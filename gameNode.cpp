//Mahir will implement this
#include "GameNode.h"
using namespace std;

GameNode::GameNode(){
    game_name = "";
}

GameNode::GameNode(int input_id,string input_name,float input_price,bool input_windows_support,bool input_mac_support,bool input_linux_support,vector<string> input_supported_languages) {
    game_id = input_id;
    game_name = input_name;
    price_in_dollars = input_price;
    windows_support = input_windows_support;
    mac_support = input_mac_support;
    linux_support = input_linux_support;
    supported_languages = input_supported_languages;
}

int GameNode::getGameID() {
    return game_id;
}

string GameNode::getGameName() {
    return game_name;
}

float GameNode::getPrice() {
    return price_in_dollars;
}

bool GameNode::getWindowsSupport() {
    return windows_support;
}

bool GameNode::getMacSupport() {
    return mac_support;
}

bool GameNode::getLinuxSupport() {
    return linux_support;
}

vector<string> GameNode::getSupportedLanguages() {
    return supported_languages;
}