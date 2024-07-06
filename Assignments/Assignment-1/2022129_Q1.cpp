#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int totalDisks, string &source, string &helper, string &helper2, string &destination) {
    if (totalDisks==1) {
        cout << source <<" -> " << destination << "     ";
        return;
    }else if (totalDisks==2) {
        cout << source <<" -> " << helper << "     ";
        cout << source <<" -> " << destination << "     ";
        cout << helper <<" -> " << destination << "     ";
        return;
    }
    towerOfHanoi(totalDisks-2, source, destination, helper2, helper);
    cout << source << " -> " << helper2 << "     ";
    cout << source <<" -> " << destination << "     ";
    cout << helper2 << " -> " << destination << "     ";
    towerOfHanoi(totalDisks-2, helper, source, helper2, destination);
}

int main() {
    // cout << "Enter the number of disks : " << endl;
    int numOfDisks;
    cin >> numOfDisks;
    string source = "T1";
    string helper = "T2";
    string helper2 = "T3";
    string destination = "T4";
    towerOfHanoi(numOfDisks, source, helper, helper2, destination);
    return 0;
}