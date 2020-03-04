#include<bits/stdc++.h>
#define FOR_TEST
using namespace std;

class Matrix{
    int col;
    int row;
    int *mat;
public:
    Matrix(int row, int col){
        this->row = row;
        this->col = col;
        mat = new int[row*col];
    };
    void input(int* a, int length);
    void print();
    void swap_node(int &a, int &b){
        a ^= b;
        b ^= a;
        a ^= b;
    }
    void transpose();
    ~Matrix(){
        if(mat != NULL){
            delete []mat;
            mat = NULL;
        }
    };
};

void Matrix:: input(int* a, int length){
    if(a == NULL || length <= 0){
        cout << "Check your input, the array can't be empty and the length must be larger than 0.\n";
        return;
    }
    for(int i = 0; i < length; i++){
        mat[i] = a[i];
    }
    if(length < row*col){
        for(int i = length; i < row*col; i++)
            mat[i] = 0;
    }
}

void Matrix:: print(){
    if(mat == NULL){
        cout << "Please input your data first.\n";
        return;
    }
    for(int i = 0; i < row; i++){
        cout << "row " << i << " :\t";
        for(int j = 0; j < col; j++){
            printf("%d\t", mat[i*col+j]);
        }
        cout << "\n";
    }
}

void Matrix:: transpose(){
    if(mat == NULL){
        cout << "Please input your data first.\n";
        return;
    }
    int newr = col, newc = row;
    int *temp = new int [col * row];
    for(int i = 0; i < col*row; i++) temp[i] = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            temp[j*row+i] = mat[i*col+j];
        }
    }
    delete []mat;
    mat = temp;
    swap_node(col, row);
}

#ifdef FOR_TEST

int main(){
    Matrix a(6, 5);
    int arr[] = {1, 2, 3, 4, 5, 6, 90, 89, 88, 87, 86, 85, 56, 78, 892, 3230, 1010,\
    2332, 9430, 9203, 2302, 8439, 2293, 3478, 7832, 2938};
    a.input(arr, 26);
    a.print();
    cout << "\n";
    a.transpose();
    a.print();
    return 0;
}

#endif