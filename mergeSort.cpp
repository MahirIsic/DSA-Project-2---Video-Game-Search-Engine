#include "mergeSort.h"

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