#include <bits/stdc++.h>
using namespace std;

// NOTE : vertices are indexed from 1 to V

void printAdjList(vector<vector<int>> &adjList) {
    for (int i = 1; i < adjList.size(); i++) {
        cout << i << " : ";
        for (auto j : adjList[i]) {
            cout << j << " ";
        } cout << endl;
    }
}

void printAdjMatrix(vector<vector<int>> &adjMatrix) {
    int n = adjMatrix.size();
    for (int i = 0; i < n; i++) {
        adjMatrix[i][0] = i;
        adjMatrix[0][i] = i;
    }
    cout << "     ";
    for (int i = 1; i < n; i++) {
        cout << i << "  ";
    } cout << endl;
    for (int i = 1; i < n; i++) {
        cout << i << " : ";
        for (int j = 1; j < n; j++) {
            if (i==0 && j==0) {
                cout << "  " << " ";
            } else {
                if (adjMatrix[i][j] <= 9) {
                    cout << " " << adjMatrix[i][j] << " ";
                } else {
                    cout << adjMatrix[i][j] << " ";
                }
            }
        } cout << endl;
    }
}

void insertEdge(vector<vector<int>> &adjMatrix, vector<vector<int>> &adjList, int u, int v) {
    // inserting edge in adj list
    unordered_set<int> temp (adjList[u].begin(), adjList[u].end());
    if (temp.count(v) != 0) {
        cout << "this edge already exists in the adj list \n";
    } else {
        adjList[u].push_back(v);
        cout << "inserted edge u -> v \n";
    }

    // inserting edge in adj matrix
    if (adjMatrix[u][v] == 1) {
        cout << "this edge already exists in the adj matrix \n";
    } else {
        adjMatrix[u][v] = 1;
        cout << "inserted edge u -> v \n";
    }
}

void deleteEdge(vector<vector<int>> &adjMatrix, vector<vector<int>> &adjList, int u, int v) {
    // inserting edge in adj list
    unordered_set<int> temp (adjList[u].begin(), adjList[u].end());
    if (temp.count(v) == 0) {
        cout << "this edge does not exist in the adj list, can't be deleted \n";
    } else {
        temp.erase(v);
        adjList[u] = vector<int>(temp.begin(),temp.end());
        cout << "edge deleted from adj list u -> v \n";
    }

    // inserting edge in adj matrix
    if (adjMatrix[u][v] == 0) {
        cout << "this edge does not exist in the adj matrix, can't be deleted \n";
    } else {
        adjMatrix[u][v] = 0;
        cout << "edge deleted from adj matrix u -> v \n";
    }
}

void dfs(vector<vector<int>> &adjList, vector<int> &visited, int source, int &time) {
    time++;
    visited[source] = 1;
    cout << "\narr time " << time << " : " << source << " ";
    for (auto i : adjList[source]) {
        if (visited[i] == 0) {
            dfs(adjList, visited, i, time);
        }
    }
}

void dfsWithoutPrinting(vector<vector<int>> &adjList, vector<int> &visited, int source) {
    visited[source] = 1;
    for (auto i : adjList[source]) {
        if (visited[i] == 0) {
            dfsWithoutPrinting(adjList, visited, i);
        }
    }
}

void bfs(vector<vector<int>> &adjList, vector<int> &visited, queue<int> &q, int source) {
    q.push(source);
    visited[source] = 1;
    int level = 0;

    while (!q.empty()) {
        int queueSize = q.size();
        cout << "level " << level << " : "; level++;
        // for every vertex in that layer
        for (int i = 0; i < queueSize; i++) {
            int currVertex = q.front();
            cout << currVertex << " ";
            q.pop();
            for (auto neighbour : adjList[currVertex]) {
                if (visited[neighbour] == 0) {
                    q.push(neighbour);
                    visited[neighbour] = 1;
                }
            }
        }
        cout << endl;
    }
}

bool isConnected(vector<vector<int>> &adjList, vector<int> &visited) {
    dfsWithoutPrinting(adjList, visited, 1);
    for (int i = 1; i < visited.size(); i++) {
        if (visited[i] == 0) {
            return 0;
        }
    } 
    return 1;
}

bool isDirected(vector<vector<int>> &adjMatrix) {
    for (int i = 1; i < adjMatrix.size(); i++) {
        for (int j = 1; j < adjMatrix.size(); j++) {
            if (adjMatrix[i][j] == 0) {
                if (adjMatrix[j][i] == 1) {
                    return 1;
                }
            } else {
                if (adjMatrix[j][i] == 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

bool hasCycleUtil(vector<vector<int>> &adjList, vector<int> &visited, vector<int> &recStack, int v) {
    if (visited[v] == 0) {
        visited[v] = 1;
        recStack[v] = 1;

        for (auto u : adjList[v]) {
            if (!visited[u] && hasCycleUtil(adjList, visited, recStack, u))
                return true;
            else if (recStack[u])
                return true;
        }
    }
    recStack[v] = 0;
    return false;
}

bool hasCycle(vector<vector<int>> &adjList) {
    int V = adjList.size() - 1;
    vector<int> visited(V + 1, 0);
    vector<int> recStack(V + 1, 0);

    for (int i = 1; i <= V; i++) {
        if (hasCycleUtil(adjList, visited, recStack, i))
            return true;
    }
    return false;
}

void topologicalSortUtil(vector<vector<int>> &adjList, vector<int> &visited, stack<int> &st, int v) {
    visited[v] = 1;
    for (auto u : adjList[v]) {
        if (!visited[u])
            topologicalSortUtil(adjList, visited, st, u);
    }
    st.push(v);
}

void topologicalSort(vector<vector<int>> &adjList) {
    int V = adjList.size() - 1;
    vector<int> visited(V + 1, 0);
    stack<int> st;

    for (int i = 1; i <= V; i++) {
        if (!visited[i])
            topologicalSortUtil(adjList, visited, st, i);
    }
    
    cout << "Topological Sort: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    cout << "enter nyumber of vertices : \n";
    int V; cin >> V;
    if (V <= 0) {cout << "enter a number greater than 0\n"; return 0;}
    // adj matrix
    vector<vector<int>> adjMatrix(V+1, vector<int>(V+1));

    // adj list
    vector<vector<int>> adjList (V+1);

    cout << "enter number of edges : \n";
    int edges, u, v; cin >> edges;
    cout << "enter edges space separated (1-based indexing) : \n";
    while (edges--) {
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjList[u].push_back(v);
    }

    // visited array of vertices
    vector<int> visited (V+1, 0);
    
    // printing adj matrix
    cout << "\nAdjacency Matrix : \n";
    printAdjMatrix(adjMatrix);

    // printing adj matrix
    cout << "\nAdjacency List : \n";
    printAdjList(adjList);

    // Depth-First Search
    cout << "\nDFS : ";
    int time = -1;
    for (int i = 1; i <= V; i++) {
        if (visited[i] == 0) {
            dfs(adjList, visited, i, time);
        }
    }

    // Breadth_First Search
    vector<int> visitedd (V+1, 0);
    cout << "\n\nBFS : \n";
    int source = 1;
    queue<int> q;
    bfs(adjList, visitedd, q, source);

    cout << "\nProperties : \n";
    // checking if graph is connected or not
    vector<int> visiteddd (V+1, 0);
    bool connected = isConnected(adjList, visiteddd);
    if (connected) {cout << "1. graph is connected \n";}
    else {cout << "1. graph is disconnected \n";}

    // determining if graph is directed or undirected
    bool directed = isDirected(adjMatrix);
    if (directed) {cout << "2. graph is directed \n";}
    else {cout << "2. graph is undirected \n";}

    // checking if graph has cycles
    bool cycle = hasCycle(adjList);
    if (cycle) {cout << "3. graph is cyclic \n";}
    else {cout << "3. graph is acyclic \n";}

    // perform topological sort on the graph
    cout << endl;
    if (cycle) {cout << "topological sort can not be performed on a cyclic graph\n";}
    else if (!directed) {cout << "topological sort can not be performed on an undirected graph\n";}
    else {topologicalSort(adjList);}

    return 0;
}