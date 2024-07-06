#include <bits/stdc++.h>
using namespace std;

// helper function to generate binary tree
void BSTGenerator(vector<int> &inputArr, unordered_map<int,vector<int>> &adj) {
    int n = inputArr.size();
    for (int i = 0; i < n; i++) {
        if (inputArr[i] != -1) {
            // left child and parent relationship
            if ((2*i)+1 < n && inputArr[(2*i)+1] != -1) {adj[inputArr[i]].push_back(inputArr[(2*i)+1]);}
            if ((2*i)+1 < n && inputArr[(2*i)+1] != -1) {adj[inputArr[(2*i)+1]].push_back(inputArr[i]);}
            // right child and parent relationship
            if ((2*i)+2 < n && inputArr[(2*i)+2] != -1) {adj[inputArr[i]].push_back(inputArr[(2*i)+2]);}
            if ((2*i)+2 < n && inputArr[(2*i)+2] != -1) {adj[inputArr[(2*i)+2]].push_back(inputArr[i]);}
        }
    }
}

void blast(int s, unordered_map<int,vector<int>> &adj, unordered_set<int> &visited) {
    queue<int> q;
    q.push(s); // push the source
    visited.insert(s);

    while (!q.empty()) {
        int levelSize = q.size(); // number of nodes in this level
        for (int i = 0; i < levelSize; ++i) {
            int curr = q.front();
            q.pop();

            cout << curr << " ";

            // Process the neighbors of the current node
            for (int neighbor : adj[curr]) {
                // If the neighbor hasn't been visited yet, mark it visited and push it into the queue
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        cout << endl; 
    }
}

int main() {
    // INPUT FORMAT
    // 15 (size)
    // 12 13 10 -1 -1 14 15 -1 -1 -1 -1 21 24 22 23
    // 14 (target)

    // creating an adj list
    unordered_map<int,vector<int>> adjList;
    
    // taking in input and populating the adj list
    vector<int> inputArray;
    int size, a; 
    cout << "enter size of array : \n";
    cin >> size;
    cout << "enter elements (space separated) (use -1 for null): \n";
    if (size <= 0) {cout << "enter a value greater than 0"; return 0;}
    for (int i = 0; i < size; i++) {
        cin >> a;
        inputArray.push_back(a);
    }
    BSTGenerator(inputArray, adjList);

    // set of all visited nodes
    unordered_set<int> visited;

    cout << "enter target element : \n";
    int target; cin >> target; 
    // checking if target exists in input tree
    bool present = 0;
    for (auto i : inputArray) {
        if (i==target) {present = 1;}
    }
    if (!present || target < 0) {
        cout << "out of bounds target entered, try again\n";
        return 0;
    }

    blast(target, adjList, visited);
    return 0;
}
