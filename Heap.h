#pragma once
#include <string>
#include <vector>
#include "GameNode.h"
using namespace std;

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
    void insert(int id,string name,float price,bool windows_support,bool mac_support,bool linux_support,vector<string> supported_languages);
    //Extracts the first value in the heap
    GameNode* extractMax();
    //Searches for every value following a certain name
    vector<GameNode*> searchByName(string name);
    vector<GameNode*> searchByID(int id);
    vector<GameNode*> searchByWindowsSupport(bool windows_support);
    vector<GameNode*> searchByMacSupport(bool mac_support);
    vector<GameNode*> searchByLinuxSupport(bool linux_support);
};
