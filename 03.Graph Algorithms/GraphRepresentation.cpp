#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, e;
    cin >> n >> e;
    int g[100][100] = {};
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
    }
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
Input:
4 4
0 1
0 2
1 2
2 3

Output:
Adjacency Matrix:
0 1 1 0
1 0 1 0
1 1 0 1
0 0 1 0

Time Complexity: O(V²) to print the matrix
Space Complexity: O(V²)


*/