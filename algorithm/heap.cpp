/*
* This file contains two class that minHeap and maxHeap both the declaration and their achievement
* Created on 4-8-2020
*/

#include<bits/stdc++.h>
using namespace std;

class minHeap{
    vector<int> h;
    // int current;
public:
    void siftDown(int start, int end);
    void siftUp(int start);
    bool insert(int n);
    bool remove();
};

class maxHeap{
    vector<int> h;
public:
    void siftDown(int start, int end);
    void siftUp(int start);
    bool insert(int n);
    bool remove();
}

/*
*
* The function will sift down the element using the iterator to compare the element with
* their child and swap them if necessary
* The function will find the smallest element and put it onto the top of the heap
* So it's used in the remove function
*
*/
void minHeap:: siftDown(int start, int end){
    int i = start, j = 2 * i + 1;
    int temp = h[i];
    while(j <= end){
        if(j < end && h[j] > h[j+1]) j++;
        if(temp <= h[j]) break;
        else{
            h[i] = h[j];
            i = j;
            j = 2 * j + 1;
        }
    }
    h[i] = temp;
}

/*
*
* The function will sift up the element using the iterator to compare the element with their
* father and swap if necessary
* The function can find the new element's right right position 
* So it's used in the insert function 
*
*/
void minHeap:: siftUp(int start){
    int j = start, i = (j-1) / 2;
    int temp = h[j];
    while(j > 0){
        if(h[i] <= temp) break;
        else{
            h[j] = h[i];
            j = i;
            i = (i-1) / 2;
        }
    }
    h[j] = temp;
}

/*
*
* insert a new element into the heap
*
*/
bool minHeap:: insert(int n){
    h.push_back(n);
    siftUp(h.size()-1);
    return true;
}

/*
*
* remove the element at the top of the heap and rebuild the heap
*
*/
bool minHeap:: remove(){
    if(!h.size()){
        cerr << "minHeap is empty!\n";
        return false;
    }
    h[0] = h[h.size()-1];
    h.erase(h.end()-1);
    siftDown(0, h.size()-1);
    return true;
}


void maxHeap:: siftDown(int start, int end){
    int i = start, j = 2 * i + 1;
    int temp = h[i];
    while(j <= end){
        if(j < end && h[j] < h[j+1]) j++;
        if(temp >= h[j]) break;
        else{
            h[i] = h[j];
            i = j;
            j = 2 * j + 1;
        }
    }
    h[i] = temp;
}

void minHeap:: siftUp(int start){
    int j = start, i = (j-1) / 2;
    int temp = h[j];
    while(j > 0){
        if(h[i] >= temp) break;
        else{
            h[j] = h[i];
            j = i;
            i = (i-1) / 2;
        }
    }
    h[j] = temp;
}

bool minHeap:: insert(int n){
    h.push_back(n);
    siftUp(h.size()-1);
    return true;
}

bool minHeap:: remove(){
    if(!h.size()){
        cerr << "minHeap is empty!\n";
        return false;
    }
    h[0] = h[h.size()-1];
    h.erase(h.end()-1);
    siftDown(0, h.size()-1);
    return true;
}