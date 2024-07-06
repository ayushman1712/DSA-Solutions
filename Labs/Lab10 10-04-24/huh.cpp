#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    int *arr;
    int heapSize;
    int capacity;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

    // heapify function
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

    void buildMinHeap() {
        for (int i = heapSize / 2 - 1; i >= 0; i--) {
            minHeapify(i);
        }
    }

public:
    // creates empty heap of max size cap
    MinHeap(int cap) {
        heapSize = 0;
        capacity = cap;
        arr = new int[cap];
    }

    // inserting an element into the heap
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
        minHeapify(i);
    }

    // deleting the root element from the heap
    void pop() {
        if (heapSize <= 0) {
            cout << "Heap is empty. Can't pop.\n";
            return;
        }
        if (heapSize == 1) {
            heapSize = 0;
            return;
        }
        arr[0] = arr[heapSize - 1];
        heapSize--;
        minHeapify(0);
    }

    // removing and returning the minimum element from the heap
    int extractMin() {
        if (heapSize <= 0) {
            cout << "Heap is empty.\n";
            return INT_MAX;
        }
        int temp = arr[0];
        arr[0] = arr[heapSize - 1];
        heapSize--;
        minHeapify(0);
        return temp;
    }

    // sorts the array in descending order
    void heapSort() {
        buildMinHeap();
        int originalHeapSize = heapSize; // Store the original heap size
        for (int i = originalHeapSize - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapSize--; // Reduce heap size for sorting
            minHeapify(0);
        }
        heapSize = originalHeapSize; // Restore the heap size
    }

    void printArray() {
        for (int i = 0; i < heapSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
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

    cout << "After extracting min element: ";
    minHeap.printArray();

    minHeap.heapSort();
    cout << "Sorted array: ";
    minHeap.printArray();

    return 0;
}
