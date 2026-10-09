#include <bits/stdc++.h>
using namespace std;
vector<int> g[10005];
int d[10005], p[10005];
void bfs(int s) {
    queue<int> q;
    for (int i = 0; i < 10005; i++) {
        d[i] = -1;
        p[i] = -1;
    }
    q.push(s);
    d[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                p[v] = u;
                q.push(v);
            }
        }
    }
}
int main() {
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int s, dest;
    cin >> s >> dest;
    bfs(s);
    if (d[dest] == -1) {
        cout << "Destination is unreachable\n";
        return 0;
    }
    cout << "shortest distance: " << d[dest] << '\n';
    vector<int> path;
    int now = dest;
    while (now != -1) {
        path.push_back(now);
        now = p[now];
    }
    reverse(path.begin(), path.end());
    cout << "shortest path: ";
    for (int v : path) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}

/*
Input
5 4
1 2
1 3
2 4
3 5
1 4

Output
shortest distance: 2
shortest path: 1 2 4

Time: O(V + E)
Space: O(V + E)

*/