#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    int index; // keeps track of original index for Q2 part (b)
    Node* next;
};

// Stack 
class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int value, int index) {
        Node* newNode = new Node;
        newNode->val = value;
        newNode->index = index;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow.\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return top->val;
    }

    int peekIndex() {
        if (isEmpty()) {
            return -1;
        }
        return top->index;
    }

    bool isEmpty() {
        return (top == nullptr);
    }
};

// Queue
class Queue {
private:
    Node* head;
    Node* tail;

public:
    Queue() : head(nullptr), tail(nullptr) {}

    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->val = value;
        newNode->next = nullptr;
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) { 
            tail = nullptr;
        }
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return head->val;
    }

    bool isEmpty() {
        return (head == nullptr);
    }
};


// part (b)
int* nextGreaterNumber(int* nums, int n) {
    int* result = new int[n];
    for (int i = 0; i < n; ++i) {
        result[i] = -1; // Initialize result array with -1
    }
    Stack stack;

    for (int i = 0; i < 2 * n; ++i) {
        int num = nums[i % n];
        while (!stack.isEmpty() && nums[stack.peekIndex()] < num) {
            result[stack.peekIndex()] = num;
            stack.pop();
        }
        if (i < n) {
            stack.push(num, i);
        }
    }
    return result;
}

int main() {
    cout << "Enter the size of array: ";
    int n;
    cin >> n;

    int* nums = new int[n];
    cout << "\nEnter the elements : ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int* result = nextGreaterNumber(nums, n);
    cout << "\nOutput: [";
    for (int i = 0; i < n; ++i) {
        cout << result[i];
        if (i < n - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    delete[] nums;
    delete[] result;

    return 0;
}