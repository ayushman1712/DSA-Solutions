/*
ANSWERS
(a) Optimal solution for checking the team validity is given below.
(b) Just a single level order traversal of the tree is enough.
*/

#include <bits/stdc++.h>
using namespace std;

int level(int ind) {
    return (int)(log2(ind+1));
}

int parent(int ind) {
    if (ind-1 < 0) {return -1;}
    return (ind-1)/2;
}

int main() {
    // INPUT FORMAT
    // 15 (size)
    // 12 13 10 -1 -1 14 15 -1 -1 -1 -1 21 24 22 23
    // 14 15 (query)
    
    // taking in input and populating the adj list
    vector<pair<int,int>> inputArray;
    int size, a; 
    cout << "enter size of array : \n";
    cin >> size;
    cout << "enter elements (space separated) (use -1 for null): \n";
    if (size <= 0) {cout << "enter a value greater than 0"; return 0;}
    for (int i = 0; i < size; i++) {
        cin >> a;
        inputArray.push_back({a, i});
    }
    cout << "enter query elements : \n";
    int y, z; cin >> y >> z; 

    // checking if query input exists in our binary tree
    bool present1 = 0, present2 = 0;
    for (auto i : inputArray) {
        if (i.first==y) {present1 = 1;}
        if (i.first==z) {present2 = 1;}
    }
    if (!present1 || !present2 || y < 0 || z < 0) {
        cout << "out of bounds query entered, try again\n";
        return 0;
    }

    // PRE-PROCESSING O(n) : storing indices of y's and z's parents
    int parent1 = 0, parent2 = 0, lv1 = 0, lv2 = 0;
    for (int i = 0; i < inputArray.size(); i++) {
        if (inputArray[i].first == y) {
            // root node ke liye parent nahi nikalna
            if (i>0) {parent1 = inputArray[parent(i)].first;}
            lv1 = level(i);
        }
        if (inputArray[i].first == z) {
            // root node ke liye parent nahi nikalna
            if (i>0) {parent2 = inputArray[parent(i)].first;}
            lv2 = level(i);
        }
    }

    // SOLVING PROBLEM IN O(1)
    if (parent1==parent2 || lv1!=lv2) {cout << "No";}
    else {cout << "Yes";}

    return 0;
}
