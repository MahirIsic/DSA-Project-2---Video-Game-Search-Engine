#include <string>
#include <vector>
#include "Heap.h"
#include "gameNode.h"
using namespace std;



void Heap::heapifyUp(vector<GameNode*>& input_heap) {
    int child = input_heap.size()-1;
    //Runs the function until either you get to the top or the function is already sorted
    while (child > 0) {
        //index of parent is set to (child-1)/2
        int parent = (child-1)/2;
        //If the parent should go after the child, you gotta switch the nodes of these two
        if (input_heap[parent]->getGameName() > input_heap[child]->getGameName()) {
            GameNode* temp = input_heap[child];
            input_heap[child] = input_heap[parent];
            input_heap[parent] = temp;
        }
        //index of child is set to index of parent
        child = parent;
    }
}

void Heap::heapifyDown(vector<GameNode*>& input_heap) {
    int parent = 0;
    while (parent < input_heap.size()) {
        //Set the largest index as the parent and set the two child indexes
        int largest = parent;
        int left_child = (parent*2)+1;
        int right_child = (parent*2)+2;
        //Find the value that would come first in alphabetical order
        if (left_child < input_heap.size() && input_heap[left_child]->getGameName() < input_heap[largest]->getGameName()) {
            largest = left_child;
        }
        if (right_child < input_heap.size() && input_heap[right_child]->getGameName() < input_heap[largest]->getGameName()) {
            largest = right_child;
        }
        //Swap the parent with the "largest" child if the "largest" val is not the parent
        if (largest != parent) {
            GameNode* temp = input_heap[largest];
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

void Heap::insert(int id,string name,float price,bool windows_support,bool mac_support,bool linux_support,unordered_set<string> supported_languages) {
    //Add the input node into the last
    GameNode* input = new GameNode(id,name,price,windows_support,mac_support,linux_support,supported_languages);
    heap.push_back(input);
    size++;
    //Heapify up
    heapifyUp(heap);
}

GameNode* Heap::extractMax() {
    //Set the first node as the last and delete the last node
    GameNode* max = heap[0];
    heap[0] = heap[size-1];
    size--;
    heap.pop_back();
    //Heapify down
    heapifyDown(heap);
    return max;
}

vector<GameNode*> Heap::searchByName(string name) {
    Heap unordered_result;
    //Iterates through the heap and inserts every value that has the name into a new heap
    for (auto i:heap) {
        if (i->getGameName() == name) {
            unordered_result.insert(i->getGameID(),i->getGameName(),i->getPrice(),i->getWindowsSupport(),i->getMacSupport(),i->getLinuxSupport(),i->getSupportedLanguages());
        }
    }
    vector<GameNode*> result;
    int result_size =unordered_result.size;
    //Sorts the result
    for (int i=0;i<result_size;i++) {
        result.push_back(unordered_result.extractMax());
    }
    return result;
}

vector<GameNode*> Heap::searchByID(int id) {
    Heap unordered_result;
    //Iterates through the heap and inserts every value that has the id into a new heap
    for (auto i:heap) {
        if (i->getGameID() == id) {
            unordered_result.insert(i->getGameID(),i->getGameName(),i->getPrice(),i->getWindowsSupport(),i->getMacSupport(),i->getLinuxSupport(),i->getSupportedLanguages());
        }
    }
    //Sorts the result
    vector<GameNode*> result;
    int result_size =unordered_result.size;
    for (int i=0;i<result_size;i++) {
        result.push_back(unordered_result.extractMax());
    }
    return result;
}

vector<GameNode*> Heap::searchByWindowsSupport(bool windows_support) {
    Heap unordered_result;
    //Iterates through the heap and inserts every value that has the input windows support into a new heap
    for (auto i:heap) {
        if (i->getWindowsSupport() == windows_support) {
            unordered_result.insert(i->getGameID(),i->getGameName(),i->getPrice(),i->getWindowsSupport(),i->getMacSupport(),i->getLinuxSupport(),i->getSupportedLanguages());
        }
    }
    //Sorts the result
    vector<GameNode*> result;
    int result_size =unordered_result.size;
    for (int i=0;i<result_size;i++) {
        result.push_back(unordered_result.extractMax());
    }
    return result;
}

vector<GameNode*> Heap::searchByLinuxSupport(bool linux_support) {
    Heap unordered_result;
    //Iterates through the heap and inserts every value that has the input linux support into a new heap
    for (auto i:heap) {
        if (i->getLinuxSupport() == linux_support) {
            unordered_result.insert(i->getGameID(),i->getGameName(),i->getPrice(),i->getWindowsSupport(),i->getMacSupport(),i->getLinuxSupport(),i->getSupportedLanguages());
        }
    }
    //Sorts the result
    vector<GameNode*> result;
    int result_size =unordered_result.size;
    for (int i=0;i<result_size;i++) {
        result.push_back(unordered_result.extractMax());
    }
    return result;
}

vector<GameNode*> Heap::searchByMacSupport(bool mac_support) {
    Heap unordered_result;
    //Iterates through the heap and inserts every value that has the input Mac support into a new heap
    for (auto i:heap) {
        if (i->getMacSupport() == mac_support) {
            unordered_result.insert(i->getGameID(),i->getGameName(),i->getPrice(),i->getWindowsSupport(),i->getMacSupport(),i->getLinuxSupport(),i->getSupportedLanguages());
        }
    }
    //Sorts the result
    vector<GameNode*> result;
    int result_size =unordered_result.size;
    for (int i=0;i<result_size;i++) {
        result.push_back(unordered_result.extractMax());
    }
    return result;
}

vector<GameNode*> Heap::searchByPrice(float min_price, float max_price) {
    Heap unordered_result;
    //Iterates through the heap and inserts every value that has the input Mac support into a new heap
    for (auto i:heap) {
        if (i->getPrice() >= min_price && i->getPrice() <= max_price) {
            unordered_result.insert(i->getGameID(),i->getGameName(),i->getPrice(),i->getWindowsSupport(),i->getMacSupport(),i->getLinuxSupport(),i->getSupportedLanguages());
        }
    }
    //Sorts the result
    vector<GameNode*> result;
    int result_size =unordered_result.size;
    for (int i=0;i<result_size;i++) {
        result.push_back(unordered_result.extractMax());
    }
    return result;
}

vector<GameNode*> Heap::searchByLanguageSupport(string language) {
    Heap unordered_result;
    //Iterates through the heap and inserts every value that contains the input supported language into a new heap
    for (auto i:heap) {
        if (i->getSupportedLanguages().count(language) != 0) {
            unordered_result.insert(i->getGameID(),i->getGameName(),i->getPrice(),i->getWindowsSupport(),i->getMacSupport(),i->getLinuxSupport(),i->getSupportedLanguages());
        }
    }
    //Sorts the result
    vector<GameNode*> result;
    int result_size =unordered_result.size;
    for (int i=0;i<result_size;i++) {
        result.push_back(unordered_result.extractMax());
    }
    return result;
}