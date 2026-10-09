#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int u, v, w;
};
int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    int source, dest;
    cin >> source >> dest;
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    dist[source] = 0;
    for (int i = 1; i < n; i++) {
        for (auto e : edges) {
            if (dist[e.u] != INT_MAX &&
                dist[e.u] + e.w < dist[e.v]) {

                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
            }
        }
    }
    // Check negative cycle
    for (auto e : edges) {
        if (dist[e.u] != INT_MAX &&
            dist[e.u] + e.w < dist[e.v]) {
            cout << "Negative cycle exists" << endl;
            return 0;
        }
    }
    if (dist[dest] == INT_MAX) {
        cout << "No path exists" << endl;
        return 0;
    }
    cout << "Shortest distance: " << dist[dest] << endl;
    vector<int> path;
    for (int v = dest; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    cout << "Path: ";
    for (int v : path) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}

/*
Input:
5 6
0 1 6
0 2 7
1 2 8
1 3 5
2 3 -3
3 4 9
0 4

Output:
Shortest distance: 13
Path: 0 2 3 4
Time Complexity: O(V × E)
Space Complexity: O(V + E)

*/