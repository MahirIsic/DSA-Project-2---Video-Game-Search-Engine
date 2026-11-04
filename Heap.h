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
    void heapifyUp(vector<GameNode>& input_heap);
    void heapifyDown(vector<GameNode>& input_heap, int parent);
public:
    vector<GameNode> heap;
    int size;

    //Creates heap
    Heap();
    Heap(const vector<GameNode>& games);

    //Inserts game into a heap
    void insert(int id,string name,float price,bool windows_support,bool mac_support,bool linux_support,unordered_set<string> supported_languages);
    
    //Extracts the first value in the heap
    GameNode extractMin();

    //Builds a heap from the current contents in O(n)
    void heapify();

    //Sorts a heap
    vector<GameNode> sortHeap(const vector<GameNode>& unordered_result);
};
