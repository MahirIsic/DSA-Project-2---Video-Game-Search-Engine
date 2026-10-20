#pragma once
#include <string>
#include <vector>
#include "Heap.h"
using namespace std;

Node::Node(){
    name = "";
    users = 0;
}

Node::Node(string n, int u) {
    name = n;
    users = u;
}

void Heap::heapifyUp(vector<Node*>& input_heap) {
    int child = input_heap.size()-1;
    //Runs the function until either you get to the top or the function is already sorted
    while (child > 0) {
        //index of parent is set to (child-1)/2
        int parent = (child-1)/2;
        //If the parent's # of users is less than the child's, you gotta switch the nodes of these two
        if (input_heap[parent]->name > input_heap[child]->name) {
            Node* temp = input_heap[child];
            input_heap[child] = input_heap[parent];
            input_heap[parent] = temp;
        }
        //index of child is set to index of parent
        child = parent;
    }
}

void Heap::heapifyDown(vector<Node*>& input_heap) {
    int parent = 0;
    while (parent < input_heap.size()) {
        //Set the largest index as the parent and set the two child indexes
        int largest = parent;
        int left_child = (parent*2)+1;
        int right_child = (parent*2)+2;
        //Find the value that would come first in alphabetical order
        if (left_child < input_heap.size() && input_heap[left_child]->name < input_heap[largest]->name) {
            largest = left_child;
        }
        if (right_child < input_heap.size() && input_heap[right_child]->name < input_heap[largest]->name) {
            largest = right_child;
        }
        //Swap the parent with the "largest" child if the "largest" val is not the parent
        if (largest != parent) {
            Node* temp = input_heap[largest];
            input_heap[largest] = input_heap[parent];
            input_heap[parent] = temp;
        }
        //Otherwise stop the function
        else {
            return;
        }
        //Set the parent as the largest value and continue the heapification
        parent = largest;
    }
}

Heap::Heap() {
    size = 0;
    heap = {};
}

void Heap::insert(string name, int users) {
    //Add the input node into the last
    Node* input = new Node(name, users);
    heap.push_back(input);
    size++;
    //Heapify up
    heapifyUp(heap);
}

Node* Heap::extractMax() {
    //Set the first node as the last and delete the last node
    Node* max = heap[0];
    heap[0] = heap[size-1];
    size--;
    heap.pop_back();
    //Heapify down
    heapifyDown(heap);
    return max;
}