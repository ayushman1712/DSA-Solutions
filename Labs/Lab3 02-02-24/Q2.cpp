#include<bits/stdc++.h>
using namespace std;

/*
low: next position to place  0
mid: element currently being examined
high: last position to place 2
*/

void colorSort(int arr[], int size){
    int low = 0, mid = 0, high = size - 1;
    while (mid <= high) {
        if (arr[mid] == 0) {
            int temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;
            low++; mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else {  // arr[mid] == 2
            int temp = arr[high];
            arr[high] = arr[mid];
            arr[mid] = temp;
            high--;
        }
    }
    // cout << low << mid << high;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int32_t main() {
    int arr[] = { 2, 2, 0, 1, 1, 0, 2, 1, 1, 0 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given unsorted array:\n";
    printArray(arr, arr_size);
 
    colorSort(arr, arr_size);
 
    cout << "\nSorted array:\n";
    printArray(arr, arr_size);

    return 0;
}
