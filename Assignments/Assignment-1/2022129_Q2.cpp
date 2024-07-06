#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int l, int mid, int r){
    int n1 = mid - l + 1; //len of lefthalf array
    int n2 = r - (mid+1) + 1; //len of righthalf array
    int leftHalf[n1], rightHalf[n2];
    for (int i = 0; i < n1; i++){
        leftHalf[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        rightHalf[j] = arr[mid+1 + j];
    }
    
    int i = 0; int j = 0; int k = l;
    while(i<n1 && j<n2){
        if(leftHalf[i] <= rightHalf[j]){
            arr[k] = leftHalf[i];
            k++;i++;
        }
        else{
            arr[k] = rightHalf[j];
            k++;j++;
        }
    }
    while(i<n1){
        arr[k] = leftHalf[i];
        k++;i++;
    }
    while(j<n2){
        arr[k] = rightHalf[j];
        k++;j++;
    }

    delete[] leftHalf;
    delete[] rightHalf;
}

void iterativeMergeSort(vector<int> &arr){
    int pass, var, low, mid, high;
    int size = arr.size();

    for (pass=1; pass<size; pass=pass*2) {
        for (var = 0; var+pass-1<size; var = var + (pass*2)) {
            low = var;
            high = min(var + (2 * pass) - 1, size - 1);
            mid = min(low + pass - 1, size - 1);
            merge(arr, low, mid, high);
        }
    }

    merge(arr, 0, (size-1)/2, size-1);
    
}

void recursiveMergeSort(vector<int> &arr, int l, int r){
    if (l>=r){
        return;
    }

    if (l<r) {
        int mid = l + ((r-l)/2);
        recursiveMergeSort(arr, l, mid);
        recursiveMergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

void printArray(vector<int> &arr)
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int32_t main() {
    vector<int> arr;
    cout << "enter array elements (comma separated) : ";
    
    string str;
    getline(cin, str);
    stringstream ss(str);
    int i;
    while(ss >> i) { 
		arr.push_back(i); 
 
		if(ss.peek() == ',') 
			ss.ignore(); 
	}
    vector<int> arr1 = arr;
 
    cout << "\n\n" << "Given array:\n";
    printArray(arr);
    iterativeMergeSort(arr);
    cout << endl << "Sorted array (Iterative call):\n";
    printArray(arr);
    recursiveMergeSort(arr1, 0, arr1.size()-1);
    cout << endl << "Sorted array (Recursive call):\n";
    printArray(arr1);

    return 0;
}