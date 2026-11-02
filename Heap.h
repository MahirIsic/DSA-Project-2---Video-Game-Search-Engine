#pragma once
#include <string>
#include <vector>
#include <unordered_set>
#include "gameNode.h"
using namespace std;
//Got help from Dogan at office hours

//This is a greater heap ordered by number of users
class Heap {
private:
    //Runs heapify up algorithm on an input vector
    void heapifyUp(vector<GameNode*>& input_heap);
    void heapifyDown(vector<GameNode*>& input_heap);
public:
    vector<GameNode*> heap;
    int size;

    //Creates heap
    Heap();
    //Inserts game into a heap
    void insert(int id,string name,float price,bool windows_support,bool mac_support,bool linux_support,unordered_set<string> supported_languages);
    //Extracts the first value in the heap
    GameNode* extractMin();
    //Sorts a heap
    vector<GameNode*> sortHeap(Heap unordered_result);
    //Searches for every value following certain criteria
    Heap searchByName(string name);
    Heap searchByID(int id);
    Heap searchByWindowsSupport(bool windows_support);
    Heap searchByMacSupport(bool mac_support);
    Heap searchByLinuxSupport(bool linux_support);
    Heap searchByPrice(float min_price, float max_price);
    Heap searchByLanguageSupport(string language);
};
