#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    int *arr;
    int heapSize;
    int capacity;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

    void minHeapify(int index) {
        int l = left(index);
        int r = right(index);
        int smallest = index;
        if (l < heapSize && arr[l] < arr[index]) {
            smallest = l;
        }
        if (r < heapSize && arr[r] < arr[smallest]) {
            smallest = r;
        }
        if (smallest != index) {
            swap(arr[index], arr[smallest]);
            minHeapify(smallest);
        }
    }

public:
    MinHeap(int cap) {
        heapSize = 0;
        capacity = cap;
        arr = new int[cap];
    }

    void insert(int key) {
        if (heapSize == capacity) {
            cout << "Heap is already full. Can't insert new element.\n";
            return;
        }
        heapSize++;
        int i = heapSize - 1;
        arr[i] = key;
        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void pop() {
        if (heapSize == 0) {
            cout << "Heap is empty. Can't pop.\n";
            return;
        }
        arr[0] = arr[heapSize - 1];
        heapSize--;
        minHeapify(0);
    }

    int extractMin() {
        if (heapSize == 0) {
            cout << "Heap is empty.\n";
            return INT_MAX;
        }
        int temp = arr[0];
        arr[0] = arr[heapSize - 1];
        heapSize--;
        minHeapify(0);
        return temp;
    }

    void printArray() {
        cout << "Sorted array: ";
        for (int i = 0; i < capacity; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++) {
        int temp; cin >> temp; 
        arr[i] = temp;
    }
    int n = sizeof(arr) / sizeof(arr[0]);

    MinHeap minHeap(n);

    for (int i = 0; i < n; i++) {
        minHeap.insert(arr[i]);
    }

    minHeap.pop(); // Deleting the root (min element)
    cout << "After deleting the root (min element): ";
    minHeap.printArray();

    int min = minHeap.extractMin(); // Extracting and returning the minimum element
    cout << "Extracted min element: " << min << endl;

    minHeap.printArray(); // Heap after extraction

    return 0;
}