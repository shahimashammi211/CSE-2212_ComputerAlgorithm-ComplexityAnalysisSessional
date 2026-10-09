#include <bits/stdc++.h>
using namespace std;
#define A pair<int, int>
vector<A> adj[1000];
priority_queue<A, vector<A>, greater<A>> pq;
int cost[1000];
int parent[1000];
void dijkstra(int s) {
    for (int i = 0; i < 1000; i++) {
        cost[i] = INT_MAX;
        parent[i] = -1;
    }
    cost[s] = 0;
    parent[s] = s;
    pq.push({0, s});
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > cost[u]) continue;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;
            if (cost[u] != INT_MAX &&
                cost[u] + weight < cost[v]) {
                cost[v] = cost[u] + weight;
                parent[v] = u;
                pq.push({cost[v], v});
            }
        }
    }
}
int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    int u, v, w;
    for (int i = 1; i <= edges; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    int source, dest;
    cin >> source >> dest;
    dijkstra(source);
    if (cost[dest] == INT_MAX) {
        cout << "No path exists" << endl;
        return 0;
    }
    cout << cost[dest] << endl;
    cout << "Traceback:" << endl;
    int x = dest;
    vector<int> traceback;
    while (x != source) {
        traceback.push_back(x);
        x = parent[x];
    }
    traceback.push_back(source);
    reverse(traceback.begin(), traceback.end());
    for (int x : traceback) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

/*
Input:
5 6
0 1 10
0 2 3
2 1 4
1 3 2
2 3 8
3 4 5
0 4

Output:
14
Traceback:
0 2 1 3 4

Dijkstra’s Shortest Path Algorithm (Greedy Algorithm)
Time Complexity: O((V + E) log V)
Space Complexity: O(V + E)
Note: Works with non-negative edge weights.
*/