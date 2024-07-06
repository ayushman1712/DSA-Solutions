#include <bits/stdc++.h>
using namespace std;

class IntStack {
private:
    static const int SIZE = 1e5;
    int stack[SIZE];
    int top_index;

public:
    // Constructor
    IntStack() {
        top_index = -1; // Initialize top_index to -1 indicating an empty stack
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (top_index >= SIZE - 1) {
            std::cout << "Stack overflow!" << std::endl;
            return;
        }
        stack[++top_index] = value;
    }

    // Function to pop an element from the stack
    void pop() {
        if (top_index < 0) {
            std::cout << "Stack underflow!" << std::endl;
            return;
        }
        top_index--;
    }

    // Function to return the top element of the stack
    int top() {
        if (top_index < 0) {
            std::cout << "Empty Stack!" << std::endl;
            return -1; // Assuming -1 represents an invalid value for the stack
        }
        return stack[top_index];
    }

    // Function to check if the stack is empty
    bool empty() {
        return top_index < 0;
    }
};

void merge(int arr[][2], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1][2], R[n2][2];
 
    // Copy data to temp arrays
    for (int i = 0; i < n1; i++) {
        L[i][0] = arr[l + i][0];
        L[i][1] = arr[l + i][1];
    }
    for (int j = 0; j < n2; j++) {
        R[j][0] = arr[m + 1 + j][0];
        R[j][1] = arr[m + 1 + j][1];
    }
 
    // Merge the temp arrays
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i][0] <= R[j][0]) {
            arr[k][0] = L[i][0];
            arr[k][1] = L[i][1];
            i++;
        }
        else {
            arr[k][0] = R[j][0];
            arr[k][1] = R[j][1];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k][0] = L[i][0];
        arr[k][1] = L[i][1];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k][0] = R[j][0];
        arr[k][1] = R[j][1];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[][2], int l, int r) {
    if (l >= r) {
        return; //returns recursively
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int* dota(int pos[], int h[], char d[], int n) {
    int arr[n][2];
    for (int i = 0; i < n; i++) {
        arr[i][0] = pos[i];
        arr[i][1] = i;
    }
    mergeSort(arr, 0, n - 1);

    IntStack stack;

    for (int i = 0; i < n; i++) {
        int ind = arr[i][1];
        char dir = d[ind];

        if (dir == 'D') {
            if (stack.empty()) {
                stack.push(ind);
            } else {
                if (d[stack.top()] == 'R' && h[stack.top()] == h[ind]) {
                    h[stack.top()] = 0;
                    stack.pop();
                    h[ind] = 0;
                } else {
                    while (!stack.empty() && d[stack.top()] == 'R' && h[stack.top()] < h[ind]) {
                        h[stack.top()] = 0;
                        stack.pop();
                        h[ind]--;
                    }
                    if (!stack.empty() && d[stack.top()] == 'R' && h[stack.top()] > h[ind]) {
                        h[stack.top()]--;
                        h[ind] = 0;
                    } else if (!stack.empty() && d[stack.top()] == 'R' && h[stack.top()] == h[ind]) {
                        h[stack.top()] = 0;
                        h[ind] = 0;
                        stack.pop();
                    } else {
                        stack.push(ind);
                    }
                }
            }
        } else {
            stack.push(ind);
        }
    }

    int* ans = new int[n];
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (h[i] > 0) {
            ans[count++] = h[i];
        }
    }

    // Displaying the result array
    cout << "\n\n[ ";
    for (int i = 0; i < count; i++) {
        cout << ans[i] << " ";
    }
    cout << "]";

    return ans;
}

int main() {
    int n; cout << "Enter Size : "; cin >> n; 
    cout  << "\nPositions : ";
    int positions[n]; 
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        positions[i] = temp;
    }
    cout  << "\nPositions : ";
    int healths[n]; 
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        healths[i] = temp;
    }
    string teams; cout << "\nTeam : "; cin >> teams;
    char team[n];
    for (int i = 0; i < n; i++) {
        team[i] = teams[i];
    }

    dota(positions, healths, team, n);
    return 0;
}