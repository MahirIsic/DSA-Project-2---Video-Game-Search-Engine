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
    void insert(string name);
    //Extracts the first value in the heap
    GameNode* extractMax();
};
