#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int g[100][100] = {};
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = w;
        g[v][u] = w;
    }
    int v[100] = {};
    int cost = 0;
    v[0] = 1;
    cout << "edge:" << endl;
    for (int i = 0; i < n - 1; i++) {
        int minw = INT_MAX;
        int u = -1, w = -1;
        for (int j = 0; j < n; j++) {
            if (v[j]) {
                for (int k = 0; k < n; k++) {
                    if (!v[k] && g[j][k] > 0 &&  g[j][k] < minw) {
                        minw = g[j][k];
                        u = j;
                        w = k;
                    }
                }
            }
        }
        if (u == -1) {
            cout << "not possible" << endl;
            return 0;
        }
        cout << u << " - " << w << " : " << minw << endl;
        cost += minw;
        v[w] = 1;
    }
    cout << "cost: " << cost << endl;
    return 0;
}

/*
Input:
4 5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4

Output:
edge:
0 - 3 : 5
3 - 2 : 4
0 - 1 : 10
cost: 19
Time Complexity: O(V²)
Space Complexity: O(V²)

*/