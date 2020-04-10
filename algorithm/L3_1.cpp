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

int main(){

}