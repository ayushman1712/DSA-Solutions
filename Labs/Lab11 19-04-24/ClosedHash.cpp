#include<bits/stdc++.h>
using namespace std;

class OpenHash {
    int m;
    int PRIME;
    vector<int> arr;
public:
    // constructor
    OpenHash(int b) {
        m = b;
        PRIME = 7;
        // -1 indicates empty slots
        // -2 indicates deleted slots
        arr = vector<int>(m, -1);
    }

    int hashFunction1(int x) {
        return (x % m);
    } 
    
    int hashFunction2(int x) {
        return PRIME - (x % PRIME); // choosing a prime number
    }

    // Linear Probe
    int linearProbe(int ind, int i) {
        return (ind + i) % m;
    }

    // Quadratic Probing
    int quadraticProbe(int ind, int i) {
        return (ind + i * i) % m;
    }

    // Double Hashing
    int doubleHash(int i, int key) {
        int h1 = hashFunction1(key);
        int h2 = hashFunction2(key);
        return (h1 + i * h2) % m;
    }

    // Insert Operation
    void insertItem(int key) {
        int i = 0;
        int index = hashFunction1(key); // Initialize index properly
        while ((arr[index] != -1 && arr[index] != -2) && i < m) {
            // Choose your collision handling technique
            // index = linearProbe(key, i);
            // index = quadraticProbe(key, i);
            index = doubleHash(i, key);
            i++;
        }
        if (i == m) {
            cout << "Hash table is full, cannot insert " << key << endl;
            return;
        }
        arr[index] = key;
    }

    // Delete Operation
    void deleteItem(int key) {
        int i = 0;
        int index = hashFunction1(key); // Initialize index properly
        while (arr[index] != -1 && i < m) {
            if (arr[index] == key) {
                arr[index] = -2; // mark as deleted
                cout << "Element " << key << " deleted from hash table." << endl;
                return;
            }
            // Choose your collision handling technique
            // index = linearProbe(key, i);
            // index = quadraticProbe(key, i);
            index = doubleHash(i, key);
            i++;
        }
        cout << "Element not found." << endl;
    }

    // Search operation
    int searchItem(int key) {
        int i = 0;
        int index = hashFunction1(key); // Initialize index properly
        while (arr[index] != -1 && arr[index] != key && arr[index] != -2 && i < m) {
            // Choose your collision handling technique
            // index = linearProbe(key, i);
            // index = quadraticProbe(key, i);
            index = doubleHash(i, key);
            i++;
        }
        if (arr[index] == key)
            return index;
        return -1; // Not found
    }

    void displayHash() {
        for (int i = 0; i < m; i++) {
            cout << i;
            cout << " -> " << arr[i];
            cout << endl;
        }
    }
};

class ClosedHash {
	int m; // number of slots
	list<int> *table; // array containing slots
public:
    // constructor
	ClosedHash(int b) {
        m = b;
	    table = new list<int>[m];
    }

	void insertItem(int key) {
        int index = hashFunction(key);
	    table[index].push_back(key); 
    }

	// deletes a key from hash table
	void deleteItem(int key) {
        int index = hashFunction(key);

        list <int> :: iterator i;
        for (i = table[index].begin();
                i != table[index].end(); i++) {
            if (*i == key)
            break;
        }

        if (i != table[index].end())
            table[index].erase(i);
            cout << "Element " << key << " deleted from hash table.\n";
    }

	// hash function to map values to key
	int hashFunction(int x) {
		return (x % m);
	}

    // serch for a key if it exists, return the slot number if it exists
    // otherwise return -INF
    int searchItem(int key) {
        int index = hashFunction(key);
        // return slot index if found
        for (auto& k : table[index]) {
            if (k == key) {
                cout << "Element: " << key << " found at index: " << index << endl;
                return index;
            }
        }
        cout << "Element not found." << endl;
        return INT_MIN; // return INT_MIN if key not found
    }

    // function to display hash table
	void displayHash() {
        cout << endl;
        for (int i = 0; i < m; i++) {
            cout << i;
            for (auto x : table[i])
            cout << " --> " << x;
            cout << endl;
        }
    }
};

int main() {
    // closed hash
    cout << "CLOSED HASH \n\n";
    int a[] = {15, 11, 27, 8, 13, 4, 5, 6, 7, 21};
    int n = sizeof(a)/sizeof(a[0]);

    ClosedHash closedHash(7);
    for (int i = 0; i < n; i++) 
        closedHash.insertItem(a[i]); 

    // deleted 13
    closedHash.deleteItem(13);

    // searching for 8
    closedHash.searchItem(8);
    
    // print hash table
    closedHash.displayHash();
    cout << "\n";

    // ===============================================================

    // Open hash
    cout << "=============================================================\n";
    cout << "OPEN HASH \n\n";
    OpenHash openHash(11); // Choosing m as 11
    int arr[] = {15, 11, 27, 8, 13, 4, 5, 6, 7, 21};
    int q = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < q; i++) 
        openHash.insertItem(arr[i]); 

    // search for 8
    int searchResult = openHash.searchItem(8);
    if (searchResult != -1)
        cout << "\nElement found at index " << searchResult << endl;
    else
        cout << "\nElement not found." << endl;

    // deletes 13
    openHash.deleteItem(13);

    // prints hash table
    openHash.displayHash();

    return 0;
}
