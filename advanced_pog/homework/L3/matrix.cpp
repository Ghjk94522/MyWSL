#include<bits/stdc++.h>
using namespace std;

class myarr{
    int *arr;
    int n;
public:
    int length() const{
        return n;
    }
    int get_num(int n) const{
        return arr[n];
    }
    int* get_arr() const{
        return arr;
    }
    myarr(int a[], int n){
        this->n = n;
        arr = new int[n];
        for(int i = 0; i < n; i++)
            arr[i] = a[i];
    }
    myarr(myarr& a){
        int length = a.length();
        arr = new int[length];
        for(int i = 0; i < length; i++)
            arr[i] = -a.get_num(i);
    }
    ~myarr(){
        if(arr != NULL){
            n = 0;
            delete[] arr;
            arr = NULL;
        }
    }
};

class matrix{
    int row, column;
    myarr arr;
public:
    void print(){
        for(int i = 0; i < row; i++){
            printf("row %d : \t", i);
            for(int j = 0; j < column; j++)
                cout << arr.get_num(i*column+j) << "\t";
            printf("\n");
        }
    }
    matrix(int r, int c, int a[]): arr(a, r*c){
        row = r;
        column = c;
    }
    matrix(matrix& m): arr(m.arr){
        row = m.row;
        column = m.column;
    }
    ~matrix(){
        row = column = 0;
    }
};

int main(){
    int a[] = {1, 2, 3, 4, 5,\
               10, 12, 14, 16, 18,\
               21, 23, 25, 27, 29,\
               77, 79, 73, 71, 75};
    matrix m1(4, 5, a);
    matrix m2(m1);
    printf("The first matrix is : \n");
    m1.print();
    printf("\nThe second matrix is : \n");
    m2.print();
    return 0;
}