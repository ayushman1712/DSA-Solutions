#include <bits/stdc++.h>
using namespace std;

// checks whether a posn (x,y) is safe or not
bool isSafe(int x, int y, vector<vector<int>> &maze) {
    int rows = maze.size();
    int cols = maze[0].size();
    if (x>=0 && x<rows && y>=0 && y<cols) {
        return(maze[x][y]==0);
    }else{
        return false;
    }
}

bool mazeSolver(int i, int j, vector<vector<int>> &maze) {
    int rows = maze.size();
    int cols = maze[0].size();
    // (rows-1) right mein
    // (cols-1) down mein
    if (i==rows-1 && j==cols-1) {
        if(maze[i][j]==0){return true;}
        else{return false;}
    }

    if(isSafe(i,j,maze)) {
        maze[i][j] = 2; // marked as visited

        // move down
        if (mazeSolver(i+1, j, maze)) {return true;}
        // move left
        if (mazeSolver(i, j-1, maze)) {return true;}
        // move right
        if (mazeSolver(i, j+1, maze)) {return true;}
        // move up
        if (mazeSolver(i-1, j, maze)) {return true;}

        // if nothing works, backtrack
        maze[i][j] = 0;
    }
    return false;
}

void mazePrinter(vector<vector<int>> &arr) {
    int size = arr.size();
    int size1 = arr[0].size();
    int i;
    for (i = 0; i < size; i++){
        cout << "[ ";
        for (int j = 0; j<size1; j++) {
            if (j==size1-1) {
                cout << arr[i][j];
            }else{
                cout << arr[i][j] << ", ";
            }
        }
        cout << " ]" << endl;
    }
    cout << endl;
}

int main() {
    vector<vector<int>> maze1 = {{1}};
    vector<vector<int>> maze2 = {{0,1,1},{0,0,1},{1,0,0}};
    cout << "Given Maze (unsolved) : " << endl;
    mazePrinter(maze2);
    bool ans = mazeSolver(0, 0, maze2);
    if (ans==true) {
        cout << "True";
    }else {
        cout << "False";
    }
    return 0;
}