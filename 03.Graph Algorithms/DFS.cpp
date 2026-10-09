#include <bits/stdc++.h>
using namespace std;
vector<int> g[10005];
bool vis[10005];
vector<int> dfslist;
void dfs(int u) {
    vis[u] = true;
    dfslist.push_back(u);
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v);
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

    int s;
    cin >> s;
    dfs(s);
    for (int v : dfslist) {
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
2 5
1

Output
1 2 4 5 3

Time: O(V + E)
Space: O(V + E)

*/