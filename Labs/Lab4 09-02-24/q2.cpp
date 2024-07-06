#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> arr){
    int size = arr.size();
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int maxMiddleSum(vector<int> &arr, int low, int mid, int high) {
    int maxLeftSum = INT_MIN;
    int maxRightSum = INT_MIN;

    // max left sum including mid element
    int currSum = 0;
    for (int i = mid; i >= low; i--) {
        currSum+=arr[i];
        maxLeftSum = max(maxLeftSum, currSum);
    }

    // max right sum excluding mid element
    currSum = 0;
    for (int i = mid+1; i <= high; i++) {
        currSum+=arr[i];
        maxRightSum = max(maxRightSum, currSum);
    }
    return maxLeftSum+maxRightSum;
}

int maxSubarraySum(vector<int> &arr, int low, int high) {
    if (low > high) { //empty array base case
        return 0;
    }
    if (low==high) {
        return arr[low];
    }
    int mid = low + ((high-low)/2);
    int maxLeftSum = maxSubarraySum(arr, low, mid);
    int maxRightSum = maxSubarraySum(arr, mid+1, high);
    int maxMidSum = maxMiddleSum(arr, low, mid, high);

    return max(max(maxLeftSum, maxRightSum), maxMidSum);
}
/*
Time Complexity: O(n logn)

Recurrence Relation: T(n) = 2T(n/2) + cn
-maxSubarraySum function splits the problem into 2 subproblems of half the size
-maxMiddleSum function runs a loop -> order O(n) 
*/
int main() {
    vector<int> arr1 = {2, 2, 4}; // 6
    vector<int> arr2 = {1, 2, 3, 4, -10, 6, 7, 8, 9}; // 30
    vector<int> arr3 = {-5, -2, -6, -1, -2, -3, -7, -4}; // -1

    cout << "Given array : ";
    printArray(arr1);
    cout << "Maximum subarray sum : " << maxSubarraySum(arr1, 0, arr1.size()-1);

    return 0;
}