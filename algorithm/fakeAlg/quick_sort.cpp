#include<bits/stdc++.h>
using namespace std;

#define __ORIGIN__
// #define __IMPROVE__


#ifdef __ORIGIN__

int partition(int a[], int l, int r){
    int pivot = a[l];
    while(l < r) {
        while(l < r && a[r] >= pivot){
            r--;
        }
        a[l] = a[r];
        while(l < r && a[l] <= pivot){
            l++;
        }
        a[r] = a[l];
    }
    a[l] = pivot;
    return l;
}

void quick_sort(int a[], int l, int r){
    if(l < r){
        int pivot = partition(a, l, r);
        quick_sort(a, l, pivot-1);
        quick_sort(a, pivot+1, r);
    }
}

#endif

#ifdef __IMPROVE__

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

// the function of quick sort
void quick_sort(int a[], int start, int end){
    // check the range of the data input
    // the flag of when to end the function
    if(start >= end)
        return;
    
    int ind = start;

    // swap the a[ind](or a[start]) and a[end]
    // put the first data to the end and wait for comparion
    swap(a[ind], a[end]);

    // compare the target data(the a[start] before)
    // with all other datas left
    int temp = start - 1;
    for(; ind < end; ind++){
        if(a[ind] < a[end]){
            temp++;
            if(temp != ind){
                swap(a[temp], a[ind]);
            }
        }
    }
    temp++;

    // put the data in the right position
    // when the target is the biggest in the range
    // the temp will be equal to the end
    swap(a[temp], a[end]);

    // process the data that be left
    quick_sort(a, start, temp-1);
    quick_sort(a, temp+1, end);
}


#endif

/// The two algorithms above will not ac the oj because the datas are designed
//  so we can choose the random index as pivot to avoid the n^2 condition

int main(){
    int n; cin >> n;
    int src[200001] = {0};
    for(int i = 0; i < n; i++){
        cin >> src[i];
    }
    quick_sort(src, 0, n-1);
    for(int i = 0; i < n ; i++){
        cout << src[i] << " ";
    }
    return 0;
}


/// The optimizition of the quick_sort
//
// Random pivot
// choose a random pivot from 0 to right - left + 1
//
/*
 *
 * pivot = rand() % (right - left + 1) + left;
 * 
 */
//
//
// Insert sort in a litle range
// when the sort processed to a little range
// the insert sort is faster than the quick sort
//
/*
 *
 * void insertSort(int a[], int left, int right){
 *     for (int i = left + 1; i <= right; i++){
 *         for (int j = i; j > 0 && a[j] < a[j-1]; j--)
 *             swap(a[j], a[j-1]);
 *     }
 * }
 * 
 * void quickSort(int a[], int left, int right){
 *     if (left >= right) return;
 *     if (right - left + 1 < 10){
 *         insertSort(a, left, right);
 *         return;
 *     }
 *     int i = left, j = right, pivot = rand() % (right - left + 1) + left;
 *     swap(a[left], a[pivot]);
 *     while(i < j){
 *         while (j > i && a[j] >= a[left]) j--;
 *         while (i < j && a[i] <= a[left]) i++;
 *         swap(a[i], (i == j) ? a[left] : a[j]);
 *     }
 *     quickSort(a, left, i-1);
 *     quickSort(a, j+1, right);
 * 
 */
//
//
// Gather repeating elements
// 
/*
 *
 * void quickSort(int a[], int left, int right){
 *     if (left >= right) return;
 *     if (right - left + 1 < 10){
 *         insertSort(a, left, right);
 *         return;     
 *     }
 *     int i = left, j = right, k, flag = 0, pivot = rand() % (right - left + 1) + left;
 *     swap(a[left], a[pivot]);
 *     while(i < j){
 *         while (j > i && a[j] >= a[left]){
 *             if (a[j] == a[left]){
 *                 for (k = j-1; k > i; k--){
 *                     if(a[k] != a[j]){
 *                         swap(a[k], a[j]);
 *                         break;
 *                     }
 *                 }
 *                 if(k == i){
 *                     if (a[left] >= a[i]) 
 *                         swap(a[left], a[i]);
 *                     else{
 *                         swap(a[i], a[j]);
 *                         swap(a[left], a[i-1]);
 *                         i--; j--;
 *                     }
 *                     flag = 1;
 *                     break;
 *                 }
 *                 else continue;
 *             }
 *             j--;
 *         }
 *         if(flag) break;
 *         while (i < j && a[i] <= a[left]){
 *             if (a[i] == a[left] && i != left){
 *                 for (k = i+1; k < j; k++){
 *                     if(a[k] != a[i]){
 *                         swap(a[k], a[i]);
 *                         break;
 *                     }
 *                 }
 *                 if(k == j){
 *                     swap(a[left], a[j]);
 *                     flag = 1;
 *                     break;
 *                 }
 *                 else continue;
 *             }
 *             i++;
 *         }
 *         if(flag) break;
 *         swap(a[i], (i == j) ? a[left] : a[j]);
 *     }
 *     quick_sort(a, left, i-1);
 *     quick_sort(a, j+1, right);
 *     return;
 * }
 * 
 */
//
//
// In addition, the independent function swap written by myself will also
// increase the time of the sort function, so just write it in the sort function
//
//