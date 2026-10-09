#include <bits/stdc++.h>
using namespace std;
int parent[100];
int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < n; i++)
        parent[i] = i;
    int totalCost = 0;
    cout << "Edges in MST:" << endl;
    for (auto e : edges) {
        int w = e.first;
        int u = e.second.first;
        int v = e.second.second;
        int a = find(u);
        int b = find(v);
        if (a != b) {
            parent[a] = b;
            totalCost += w;
            cout << u << " - " << v << " : " << w << endl;
        }
    }
    cout << "Total Cost: " << totalCost << endl;
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
Edges in MST:
2 - 3 : 4
0 - 3 : 5
0 - 1 : 10
Total Cost: 19

Kruskal’s Algorithm (Greedy)
Time Complexity: O(E log E)
Space Complexity: O(V + E)

*/