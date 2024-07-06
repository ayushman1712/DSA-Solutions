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

void mergeSort(int arr[], int l, int r){
    if (l>=r){
        return;
    }

    if (l<r) {
        int mid = l + ((r-l)/2);
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int32_t main() {
    int arr[] = { -12, 11, 13, 5, 6, 7 };
    int k = 3; // to find the kth largest element
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given array:\n";
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);

    cout << endl << "Sorted array:\n";
    printArray(arr, arr_size);
    
    if ((k < 1) || (k > arr_size)) {
        cout << endl << "value of k out of array's index range";
    } else {
        cout << "\nKth largest element:\n";
        cout << arr[arr_size-k]; // prints the kth largest element
    }

    return 0;
}