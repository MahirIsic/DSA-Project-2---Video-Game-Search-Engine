#pragma once
#include <string>
#include <vector>
using namespace std;
//Got help from Cole at office hours.

class Node{
public:
    string name;
    int users;

    //Creates a node with no info about the game
    Node();

    //Creates a node with already filled info about the game
    Node(string n, int u);
};

//This is a greater heap ordered by number of users
class Heap {
private:
    //Runs heapify up algorithm on an input vector
    void heapifyUp(vector<Node*>& input_heap);
    void heapifyDown(vector<Node*>& input_heap);
public:
    vector<Node*> heap;
    int size;

    //Creates heap
    Heap();
    //Inserts game into a heap
    void insert(string name, int users);
    //Extracts the first value in the heap
    Node* extractMax();
};
