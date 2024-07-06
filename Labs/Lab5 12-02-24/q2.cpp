#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr)
{
    int size = arr.size();
    cout << "{ ";
    for (int i = 0; i < size; i++)
        if (i==size-1) {
            cout << arr[i];
        }else{
            cout << arr[i] << ", ";
        }
    cout << " }";
    cout << endl;
}

int generateRandomPivot(int low, int high) { 
    // low = first index 
    // high = last index
    int randomNumber = rand();
    int range = high - low + 1;
    int pivot = low + (randomNumber % range);

    
    srand(time(0));
    return rand() % (range) + low;
}

void swap(vector<int> &arr, int ind1, int ind2) {
    int temp = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = temp;
}

// int partition(vector<int> &arr, int low, int high) {
//     int pivot = generateRandomPivot(low, high);
//     swap(arr, low, pivot);
//     int x = arr[low];
//     int i = low;
//     for (int j = low+1; j<=high; j++) {
//         if (arr[j]<x) {
//             i++;
//             swap(arr, i, j);
//         }
//     }
//     swap(arr, low, i);
//     return i;
// }

int partition(vector<int> &arr, int low, int high) {
    int pivotIndex = generateRandomPivot(low, high); // Generate random pivot index
    int pivot = arr[pivotIndex]; // Get the value of the pivot
    cout << "Pivot: " << pivot << endl << "Partitions: {";
    
    // Swap the pivot with the last element
    swap(arr[pivotIndex], arr[high]);
    
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] > pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // Swap the pivot back to its correct position
    swap(arr[i + 1], arr[high]);
    
    // Display the partitions
    for (int q = low; q <= i; q++) {
        cout << arr[q] << " ";
    }
    cout << "} and {";
    for (int q = i + 2; q <= high; q++) {
        cout << arr[q] << " ";
    }
    cout << "}" << endl;
    
    return i + 1; // Return the index of the pivot
}


void quickSort(vector<int> &arr, int low, int high) {
    if (low<high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int32_t main() {
    vector<int> arr = {4,6,3,5,-12,-3,24,0,13,1};
    cout << "Given array (unsorted) : " << endl;
    printArray(arr);
    cout << endl;
    quickSort(arr, 0, arr.size()-1);
    cout << endl << "Sorted array (using QuickSort) : " << endl;
    printArray(arr);
    // int arrlen;
    // cout << "enter array length : " << endl;
    // cin >> arrlen;
    // vector<int> arr;
    // for (int i = 0; i<arrlen; i++) {
    //     int temp; 
    //     cin >> temp;
    //     arr.push_back(temp);
    // }
 
    // minMax(arr);
    return 0;
}