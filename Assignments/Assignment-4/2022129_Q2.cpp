#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cout << "enter size of array : \n";
    cin >> n;
    vector<int> arr;
    unordered_set<int> checker;
    vector<vector<pair<int,int>>> remainderPairs(1000000);

    cout << "enter array elements : \n";
    for (int j = 0; j < n; j++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
        if (checker.count(temp) == 0) {
            // checker makes sure that no value is calculated more than once
            checker.insert(temp);
            for (auto s : arr) {
                remainderPairs[s%temp].push_back({s,temp});
                remainderPairs[temp%s].push_back({temp,s});
            }
        }
    }
    cout << "enter k : \n";
    int k = n; cin >> k;


    // return output
    vector<pair<int,int>> ans = remainderPairs[k];
    for (int i = 0; i < (ans).size(); i++) {
        cout << "(" << ans[i].first << "," << ans[i].second << ")\n";
    }

    return 0;
}