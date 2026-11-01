#include <iostream>
#include "heap.h"
#include "mergeSort.h"
using namespace std;

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

int main() {

    GameNode game1(1, "Game3", 4.99, true, true, true, {"English"});
    GameNode game2(5, "Game5", 3.99, true, true, true, {"English"});
    GameNode game3(3, "Game7", 5.99, true, true, true, {"English"});
    GameNode game4(0, "Game1", 6.99, true, true, true, {"English"});
    GameNode game5(123, "Game2", 13.99, true, true, true, {"English"});
    GameNode game6(6, "Game4", 25.99, true, true, true, {"English"});
    vector<GameNode> games;
    games.push_back(game1);
    games.push_back(game2);
    games.push_back(game3);
    games.push_back(game4);
    games.push_back(game5);
    games.push_back(game6);
    mergeSort(games, 0, games.size()-1, compareIDs);
    for(int i = 0;i < games.size();i++)
    {
        cout << games[i].getGameName() << ": " << games[i].getGameID() << "  Price: " << games[i].getPrice() << endl;
    }

    return 0;
}