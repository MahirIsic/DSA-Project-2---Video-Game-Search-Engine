//
// Created by marce on 10/11/2026.
//
#pragma once
#ifndef DSAPROJECT2_HEAP_H
#define DSAPROJECT2_HEAP_H
#include <string>
#include <vector>
using namespace std;
#endif //DSAPROJECT2_HEAP_H
//Got help from Cole at office hours.

class Node{
public:
    string name;
    int users;

    //Creates a node with no info about the game
    Node() {
        name = "";
        users = 0;
    }

    //Creates a node with already filled info about the game
    Node(string n, int u) {
        name = n;
        users = u;
    }
};

//This is a greater heap ordered by number of users
class Heap {
private:
    //Runs heapify up algorithm on an input vector
    void heapifyUp(vector<Node*>& input_heap){
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
    void heapifyDown(vector<Node*>& input_heap) {
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
public:
    vector<Node*> heap;
    int size;

    Heap() {
        size = 0;
        heap = {};
    }

    void insert(string name, int users) {
        //Add the input node into the last
        Node* input = new Node(name, users);
        heap.push_back(input);
        size++;
        //Heapify up
        heapifyUp(heap);

    }

    Node* extractMax() {
        //Set the first node as the last and delete the last node
        Node* max = heap[0];
        heap[0] = heap[size-1];
        size--;
        heap.pop_back();
        //Heapify down
        heapifyDown(heap);
        return max;
    }
};