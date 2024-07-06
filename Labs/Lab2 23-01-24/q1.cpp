#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* 
QUESTION 1: INSERTION SORT
*/

int calculateInvCount(int arr[], int n){
    int invCount = 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (arr[i] > arr[j]){
                invCount++;
            }
        }
    }

    return invCount;
}

int main() {
    int arrr[5] = {5,4,3,2,1};
    int a = calculateInvCount(arrr, 5);
    cout << a;
}

/*
output
{1} -> 0
{2,1} -> 1
{3,2,1} -> 3
{4,3,2,1} -> 6
{5,4,3,2,1} -> 10
{6,5,4,3,2,1} -> 15

therefore for an array with {n, n-1, n-2, ... , 2, 1} 
of length 'n' the number of inversions would be nC2 = n(n-1)/2
*/
