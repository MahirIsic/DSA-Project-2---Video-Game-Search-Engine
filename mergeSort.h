#pragma once
#include <vector>
#include "gameNode.h"
using std::vector;

template <typename function>
void merge(vector<GameNode>& games, int left, int mid, int right, function compare)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    vector<GameNode> leftList(leftSize);
    vector<GameNode> rightList(rightSize);
    for(int i = 0; i < leftSize;i++)
    {
        leftList[i] = games[left + i];
    }
    for(int i = 0;i < rightSize;i++)
    {
        rightList[i] = games[mid + i + 1];
    }

    int leftPtr = 0;
    int rightPtr = 0;
    int mergedPtr = left;

    while(leftPtr < leftSize && rightPtr < rightSize)
    {  
        if(compare(leftList[leftPtr], rightList[rightPtr]))
            games[mergedPtr++] = leftList[leftPtr++];
        else
            games[mergedPtr++] = rightList[rightPtr++];
    }
    while(leftPtr < leftSize)
    {
        games[mergedPtr++] = leftList[leftPtr++];
    }
    while(rightPtr < rightSize)
    {
        games[mergedPtr++] = rightList[rightPtr++];
    }
}

template <typename function>
void mergeSort(vector<GameNode>& games, int start, int end, function compare)
{
    if(start < end)
    {
        int middle = (start + end) / 2;
        mergeSort(games, start, middle, compare);
        mergeSort(games, middle + 1, end, compare);
        merge(games, start, middle, end, compare);
    }
}
bool compareNames(GameNode first, GameNode other);
bool compareIDs(GameNode first, GameNode other);
bool comparePrice(GameNode first, GameNode other);