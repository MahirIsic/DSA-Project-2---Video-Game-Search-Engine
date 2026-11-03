#include "mergeSort.h"

vector<GameNode> searchByName(vector<GameNode>& games, string name)
{
    vector<GameNode> result;
    for(int i = 0;i < games.size(); i++)
    {
        if(games[i].getGameName() == name)
            result.push_back(games[i]);
    }
    return result;
}

GameNode searchByID(vector<GameNode>& games, int id)
{
    for(int i = 0;i < games.size(); i++)
    {
        if(games[i].getGameID() == id)
            return games[i];
    }
}

vector<GameNode> searchByWindowSupport(vector<GameNode>& games)
{
    vector<GameNode> result;
    for(int i = 0; i < games.size(); i++)
    {
        if(games[i].getWindowsSupport())
            result.push_back(games[i]);
    }
    return result;
}

vector<GameNode> searchByMacSupport(vector<GameNode>& games)
{
    vector<GameNode> result;
    for(int i = 0; i < games.size(); i++)
    {
        if(games[i].getMacSupport())
            result.push_back(games[i]);
    }
    return result;
}

vector<GameNode> searchByLinuxSupport(vector<GameNode>& games)
{
    vector<GameNode> result;
    for(int i = 0; i < games.size(); i++)
    {
        if(games[i].getLinuxSupport())
            result.push_back(games[i]);
    }
    return result;
}

vector<GameNode> searchByPrice(vector<GameNode>& games, float min_price, float max_price)
{
    vector<GameNode> result;
    for(int i = 0; i < games.size(); i++)
    {
        if(games[i].getPrice() <= max_price && games[i].getPrice() >= min_price)
            result.push_back(games[i]);
    }
    return result;
}

vector<GameNode> searchByLanguageSupport(vector<GameNode>& games, string language)
{
    vector<GameNode> result;
    for(int i = 0; i < games.size(); i++)
    {
        if(games[i].getSupportedLanguages().count(language) != 0)
            result.push_back(games[i]);
    }
    return result;
}

bool compareNames(GameNode& first, GameNode& other)
{
    return first.getGameName() < other.getGameName();
}

bool compareIDs(GameNode& first, GameNode& other)
{
    return first.getGameID() < other.getGameID();
}

bool comparePrice(GameNode& first, GameNode& other)
{
    return first.getPrice() < other.getPrice();
}