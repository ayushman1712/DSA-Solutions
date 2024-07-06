#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* 
QUESTION 2: MERGE SORT
*/

long long merge(int arr[], int l, int mid, int r){
    long long inv = 0;
    int n1 = mid - l + 1;
    int n2 = r - (mid+1) + 1;
    int leftHalf[n1], rightHalf[n2];
    for (int i = 0; i < n1; i++)
        leftHalf[i] = arr[l + i];
    for (int j = 0; j < n2; j++) 
      rightHalf[j] = arr[mid +j+1];
    int i = 0; int j = 0; int k = l;
    while(i<n1 && j<n2){
        if(leftHalf[i] <= rightHalf[j]){
            arr[k] = leftHalf[i];
            k++;i++;
        }
        else{
            arr[k] = rightHalf[j];
// if a[i] > b[j] then all elements after a[i] will also be greater than b[j]
            inv += n1 - i; 
            k++;j++;
        }
    }
    while(i<n1){
        arr[k] = leftHalf[i];
        k++;i++;
    }
    while(j<n2){
        arr[k] = rightHalf[j];
        k++;j++;
    }

    return inv;
}

long long mergeSort(int arr[], int l, int r){
    long long inv = 0;
    if (l<r) {
        int mid = (l+r)/2;
        inv += mergeSort(arr, l, mid);
        inv += mergeSort(arr, mid+1, r);
        inv += merge(arr, l, mid, r);
    }
    return inv;
}


int32_t main() {
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << mergeSort(arr,0,n-1);
    return 0;
}

/*
the more the number of inversions, the more unsorted is the input array

Worst Case Scenario:
- the array is completely inverted
- max number of inverions = n(n-1)/2  
- the algorithm will swap/invert numbers for every comparison it makes
- thus, adding to the overall time complexity
- the time complexity is O(n log(n))

Best Case Scenario:
- the array is completely sorted
- number of inverions = 0 
- the algorithm will never swap/invert numbers for any comparison it makes
- the array will get partitioned and then will get merged very fast since no inversions are needed
- thus, reducing the overall actual timez
- the time complexity still remains O(n log(n))
*/