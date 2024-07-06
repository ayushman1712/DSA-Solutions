#include <bits/stdc++.h>
using namespace std;

// for each iteration of dfs, 
void dfsFlooding(vector<vector<char>> &grid, vector<vector<int>> &visited2, int i, int j) {
    grid[i][j] = 'F';
    if (i-1 >= 0 && visited2[i-1][j] == 1 && grid[i-1][j] == 'N') {dfsFlooding(grid, visited2, i-1, j);}
    if (i+1 < grid.size() && visited2[i+1][j] == 1 && grid[i+1][j] == 'N') {dfsFlooding(grid, visited2, i+1, j);}
    if (j-1 >= 0 && visited2[i][j-1] == 1 && grid[i][j-1] == 'N') {dfsFlooding(grid, visited2, i, j-1);}
    if (j+1 < grid[0].size() && visited2[i][j+1] == 1 && grid[i][j+1] == 'N') {dfsFlooding(grid, visited2, i, j+1);}
}

void dfs(vector<vector<char>> &grid, vector<vector<int>> &visited, vector<vector<int>> &visited2, int i, int j, bool &floodFlag) {
    if (i == 0 || i == grid.size() - 1 || j == 0 || j == grid[0].size() - 1) {
        floodFlag = false;
    }
    visited[i][j] = 1;
    visited2[i][j] = 1;
    if (i-1 >= 0 && visited[i-1][j] == 0 && grid[i-1][j] == 'N') {dfs(grid, visited, visited2, i-1, j, floodFlag);}
    if (i+1 < grid.size() && visited[i+1][j] == 0 && grid[i+1][j] == 'N') {dfs(grid, visited, visited2, i+1, j, floodFlag);}
    if (j-1 >= 0 && visited[i][j-1] == 0 && grid[i][j-1] == 'N') {dfs(grid, visited, visited2, i, j-1, floodFlag);}
    if (j+1 < grid[0].size() && visited[i][j+1] == 0 && grid[i][j+1] == 'N') {dfs(grid, visited, visited2, i, j+1, floodFlag);}
}

int main() {
    int m, n;
    cout << "enter number of rows : \n";
    cout << "enter number of cols : \n";
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    cout << "enter elements of the grid : \n";
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j++) {
            char temp;
            cin >> temp;
            if (temp == 'F' || temp == 'N') {
                grid[i][j] = temp; // 1 represents non-flooded areas
            } else {
                cout << "invalid character entered \n";
                return 1;
            }
        }
    }

    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size()));

    // call flooding routine
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (visited[i][j] == 0 && grid[i][j]=='N') {
                bool floodFlag = true; // Initialize floodFlag to true
                vector<vector<int>> visited2(grid.size(), vector<int>(grid[0].size()));
                dfs(grid, visited, visited2, i, j, floodFlag);
                if (floodFlag) { // Call dfsFlooding only if floodFlag is false
                    dfsFlooding(grid, visited2, i, j);
                }
            }
        }
    }

    for (auto i : grid) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
