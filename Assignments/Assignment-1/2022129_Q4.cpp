#include<bits/stdc++.h>
using namespace std;

void minMax(vector<int> &arr) {
    int size = arr.size();
    
    for (int len = 1; len<=size; len++) {
        vector<int> maxOfMin;
        for (int j = 0; j<=size-len; j+=len){
            int start = j;
            int end = j + len;
            vector<int> temp;
            for (int p = start; p<end; p++) {
                temp.push_back(arr[p]);
            }
            int min = *min_element(temp.begin(), temp.end());
            maxOfMin.push_back(min);
        }
        int ans = *max_element(maxOfMin.begin(), maxOfMin.end());
        cout << "For subarrays of size " << len << ": " << ans << endl;
    }
}

int32_t main() {
    int arrlen;
    cout << "enter array length : " << endl;
    cin >> arrlen;
    vector<int> arr;
    for (int i = 0; i<arrlen; i++) {
        int temp; 
        cin >> temp;
        arr.push_back(temp);
    }
 
    minMax(arr);
    return 0;
}