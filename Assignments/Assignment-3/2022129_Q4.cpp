#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data, count = 1, size = 1, height = 1;
    Node *left = nullptr, *right = nullptr;

    Node(int val) : data(val) {}
};

/*
In each node:
- count : number of occurrences of the task ID in the tree. Since we allow duplicates in the tree, count keeps track of how many times the same task ID appears in the tree
- size : number of nodes in the subtree rooted at the current node, including itself
- height : height of the subtree rooted at the current node, (the number of edges on the longest path from the node to a leaf node)
*/

class AVL {
private:
    Node *root;

    int height(Node *node) {
        return node ? node->height : 0;
    }

    int size(Node *node) {
        return node ? node->size : 0;
    }

    int balanceFactor(Node *node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        y->size = size(y->left) + size(y->right) + y->count;
        x->size = size(x->left) + size(x->right) + x->count;

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        x->size = size(x->left) + size(x->right) + x->count;
        y->size = size(y->left) + size(y->right) + y->count;

        return y;
    }

    Node* balance(Node* node) {
        if (node == nullptr)
            return nullptr;

        node->height = max(height(node->left), height(node->right)) + 1;
        node->size = size(node->left) + size(node->right) + node->count;

        int bf = balanceFactor(node);

        if (bf > 1 && balanceFactor(node->left) >= 0)
            return rotateRight(node);

        if (bf > 1 && balanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (bf < -1 && balanceFactor(node->right) <= 0)
            return rotateLeft(node);

        if (bf < -1 && balanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node* insert(Node* node, int val) {
        if (node == nullptr)
            return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        else
            node->count++;

        return balance(node);
    }

    int kthSmallest(Node* node, int k) {
        if (node == nullptr)
            return -1;

        int leftSize = size(node->left);
        if (k <= leftSize)
            return kthSmallest(node->left, k);
        else if (k > leftSize + node->count)
            return kthSmallest(node->right, k - leftSize - node->count);
        else
            return node->data;
    }

    Node* findMedianNode(Node* node, int& targetIndex) {
        if (node == nullptr)
            return nullptr;

        Node* result = nullptr;
        if (targetIndex <= size(node->left)) {
            result = findMedianNode(node->left, targetIndex);
        } else if (targetIndex == size(node->left) + node->count) {
            result = node;
        } else {
            targetIndex -= size(node->left) + node->count;
            result = findMedianNode(node->right, targetIndex);
        }

        return result;
    }

    Node* remove(Node* node, int val) {
        if (node == nullptr)
            return nullptr;

        if (val < node->data)
            node->left = remove(node->left, val);
        else if (val > node->data)
            node->right = remove(node->right, val);
        else {
            if (node->count > 1) {
                node->count--;
            } else {
                if (node->left == nullptr || node->right == nullptr) {
                    Node* temp = node->left ? node->left : node->right;
                    delete node;
                    return temp;
                } else {
                    Node* successor = node->right;
                    while (successor->left)
                        successor = successor->left;
                    node->data = successor->data;
                    node->count = successor->count;
                    successor->count = 1;
                    node->right = remove(node->right, successor->data);
                }
            }
        }
        return balance(node);
    }

public:
    AVL() : root(nullptr) {
        srand(time(0));
    }

    void insertTask(int taskID) {
        root = insert(root, taskID);
    }

    int queryYuji() {
        int choice = rand() % 2;

        Node* current = root;
        if (choice == 0) {
            cout << "(min) : ";
            while (current->left)
                current = current->left;
        } else {
            cout << "(max) : ";
            while (current->right)
                current = current->right;
        }

        int taskID = current->data;
        root = remove(root, taskID);
        return taskID;
    }

    int queryMegumi(int k) {
        int taskID = kthSmallest(root, k);
        root = remove(root, taskID);
        return taskID;
    }

    int queryNobara() {
        int totalTasks = size(root);
        int targetIndex = (totalTasks + 1) / 2;
        Node* medianNode = findMedianNode(root, targetIndex);

        if (medianNode) {
            int taskID = medianNode->data;
            root = remove(root, taskID);
            return taskID;
        }

        return -1;
    }
};

int main() {
    srand(time(0));
    vector<int> tasks;
    int size, a; 
    cout << "enter size of array : \n";
    cin >> size;
    cout << "enter elements (space separated) : \n";
    if (size <= 0) {cout << "enter a value greater than 0"; return 0;}
    for (int i = 0; i < size; i++) {
        cin >> a;
        tasks.push_back(a);
    }

    AVL taskManager;
    for (int task : tasks)
        taskManager.insertTask(task);

    // avoiding errors (himanshu reference)=======================================
    const int dataSize = 1000;
    vector<int> data(dataSize);
    for (int i = 0; i < dataSize; ++i) {
        data[i] = rand() % 1000; // Generate random numbers between 0 and 999
    }
    int sum = 0;
    for (int num : data) {
        sum += num;
    }
    sort(data.begin(), data.end());
    int median;
    if (dataSize % 2 == 0) {
        median = (data[dataSize / 2 - 1] + data[dataSize / 2]) / 2;
    } else {
        median = data[dataSize / 2];
    }
    int maxElement = *max_element(data.begin(), data.end());
    int minElement = *min_element(data.begin(), data.end());
    double mean = static_cast<double>(sum) / dataSize;
    //============================================================================


    cout << "enter no. of queries : \n";
    int q, uwack; cin >> q;
    while (q--) {
        cin >> uwack;
        if (uwack==1) {
            int yo = taskManager.queryYuji();
            cout << yo << endl;
        } else if (uwack==2) {
            int k;
            cout << "enter k : \n";
            cin >> k;
            int huh = taskManager.queryMegumi(k);
            cout << huh << endl;
        } else if (uwack==3) {
            int wow = taskManager.queryNobara();
            cout << wow << endl;
        } else {
            cout << "enter a number between 1 to 3";
        }
    }
    return 0;
}