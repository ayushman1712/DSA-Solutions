#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

class LinkedList {
public:
    Node *head, *tail;
    LinkedList() : head(NULL), tail(NULL) {}

    void add(int val) {
        Node *newNode = new Node(val);
        if (head==NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
};

Node* rotate(Node* head, int k) {
    if (head==NULL || k == 0) return head;

    // converting it into a circular linked list
    int sizeOfLinkedList = 1;
    Node *tail = head;
    while (tail->next) {
        tail = tail->next;
        sizeOfLinkedList+=1;
    }
    tail->next = head; 

    // rotating the LL n times, means making no change at all (n = no. of nodes)
    k = k % sizeOfLinkedList;

    // (sizeOfLinkedList - k) - 1 => steps to new tail
    Node *newTail = head;
    for (int i = 0; i < (sizeOfLinkedList - k) - 1; i++) {
        newTail = newTail->next;
    }

    Node *newHead = newTail->next;

    // making the LL non-circular
    newTail->next = nullptr;

    return newHead;
}

void linkedListPrinter(Node *head) {
    Node *temp = head;
    cout << temp->val;
    temp = temp -> next;
    while (temp != NULL) {
        cout << " -> " << temp->val;
        temp = temp->next;
    }
    cout << endl;
}

int32_t main() {
    int size;
    cin >> size;
    if (size==0) {
        return 0;
    }
    int temp;
    LinkedList list;
    while (size--) {
        cin >> temp;
        list.add(temp);
    }
    int k;
    cin >> k;

    cout << "Original list: ";
    linkedListPrinter(list.head);

    list.head = rotate(list.head, k);

    cout << "Rotated list: ";
    linkedListPrinter(list.head);

    return 0;
}