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

void swap(vector<int> &arr, int ind1, int ind2) {
    int temp = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = temp;
}

// int partition(vector<int> &arr, int low, int high) {
//     int pivot = high;
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
//     cout << "pivot : " << arr[pivot] << '\n';
//     return i;
// }

void printPartitions(vector<int> &arr, int pivotIndex, int low, int high) {
    cout << "Array Partition (Pivot: " << arr[pivotIndex] << "): ";
    for (int i = low; i <= high; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(vector<int> &arr, int low, int high) {
    int pivot = high;
    cout << "Pivot: " << arr[high] << endl << "Partitions: {";
    int x = arr[pivot];
    int i = low - 1;
    for (int j = low; j <= high; ++j) {
        if (arr[j] < x) {
            i++;
            swap(arr, i, j);
        }
    }
    for (int q = 0; q < i+1; q++) {
        cout << arr[q] << " ";
    }
    cout << "} and {";
    for (int q = i+1; q < high; q++) {
        cout << arr[q] << " ";
    }
    cout << "}" << endl;
    swap(arr, i + 1, pivot);
    // printPartitions(arr, i + 1, low, high);
    // printArray(arr);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low<high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int32_t main() {
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
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