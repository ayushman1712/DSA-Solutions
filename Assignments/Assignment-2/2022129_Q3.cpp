#include <bits/stdc++.h>
using namespace std;

// Recursive binary search function
long long binarySearch(const string& recipe, int nb, int ns, int nc, int pb, int ps, int pc, long long left, long long right, long long r) {
    if (left > right) return right;

    long long mid = left + (right - left) / 2;

    // counts number of breads, salmons, corns in mid number of sushis
    long long countB = 0;
    long long countS = 0;
    long long countC = 0;
    for (int i = 0; i < recipe.size(); i++) {
        if (recipe[i] == 'B') {countB++;}
        else if (recipe[i] == 'S') {countS++;}
        else if (recipe[i] == 'C') {countC++;}
    }
    countB *= mid;
    countS *= mid;
    countC *= mid;

    long long costB = (countB > nb) ? (countB - nb) : 0;
    long long costS = (countS > ns) ? (countS - ns) : 0;
    long long costC = (countC > nc) ? (countC - nc) : 0;

    long long totalCost = costB * pb + costS * ps + costC * pc;

    if (totalCost <= r)
        return binarySearch(recipe, nb, ns, nc, pb, ps, pc, mid + 1, right, r);
    else
        return binarySearch(recipe, nb, ns, nc, pb, ps, pc, left, mid - 1, r);
}

// Function to find the maximum number of sushi plates
long long sushiMaker(const string& recipe, int nb, int ns, int nc, int pb, int ps, int pc, long long r) {
    return binarySearch(recipe, nb, ns, nc, pb, ps, pc, 0, r, r);
}

int main() {
    string recipe;
    int nb, ns, nc, pb, ps, pc;
    long long r;

    cout << "Enter recipe: "; cin >> recipe; cout << endl;
    cout << "Enter the number of bread: "; cin >> nb; cout << endl;
    cout << "Enter the number of salmon: "; cin >> ns; cout << endl;
    cout << "Enter the number of corn: "; cin >> nc; cout << endl;
    cout << "Enter price of bread: "; cin >> pb; cout << endl;
    cout << "Enter price of salmon: "; cin >> ps; cout << endl;
    cout << "Enter price of corn: "; cin >> pc; cout << endl;
    cout << "Enter budget: "; cin >> r; cout << endl;

    cout << endl << "Maximum number of sushi: " << sushiMaker(recipe, nb, ns, nc, pb, ps, pc, r) << endl;

    return 0;
}
