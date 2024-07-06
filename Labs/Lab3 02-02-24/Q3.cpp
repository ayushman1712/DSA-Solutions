#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int mid, int r){
    int n1 = mid - l + 1; //len of lefthalf array
    int n2 = r - (mid+1) + 1; //len of righthalf array
    int leftHalf[n1], rightHalf[n2];
    for (int i = 0; i < n1; i++){
        leftHalf[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        rightHalf[j] = arr[mid+1 + j];
    }
    
    int i = 0; int j = 0; int k = l;
    while(i<n1 && j<n2){
        if(leftHalf[i] <= rightHalf[j]){
            arr[k] = leftHalf[i];
            k++;i++;
        }
        else{
            arr[k] = rightHalf[j];
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

    delete[] leftHalf;
    delete[] rightHalf;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int32_t main() {
    int arr[] =  { 2, 3, 8, -1, 7, 10 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given array:\n";
    printArray(arr, arr_size);
    int mid;
    if (arr_size%2 == 0) {
        mid = (arr_size/2)-1;
    }
    else {
        mid = arr_size/2;
    }
    merge(arr, 0, mid, arr_size - 1);
 
    cout << "\nSorted array::\n";
    printArray(arr, arr_size);
    
    return 0;
}
