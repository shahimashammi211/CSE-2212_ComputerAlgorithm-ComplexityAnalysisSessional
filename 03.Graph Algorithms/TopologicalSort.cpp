#include <bits/stdc++.h>
using namespace std;
int indeg[1000];
vector<int> adj[1000];
vector<int> toplist;
set<int> se;
queue<int> q;
void topsort() {
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        toplist.push_back(top);
        for (int i = 0; i < adj[top].size(); i++) {
            int v = adj[top][i];
            indeg[v]--;
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }
}
int main() {
    int n, e;
    cin >> n >> e;
    char u, v;
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        int uu = u - 'A' + 1;
        int vv = v - 'A' + 1;
        indeg[vv]++;
        adj[uu].push_back(vv);
        se.insert(uu);
        se.insert(vv);
    }
    for (int x : se) {
        if (indeg[x] == 0) {
            q.push(x);
        }
    }
    topsort();
    if (toplist.size() != se.size()) {
        cout << "Topological sort not possible";
        return 0;
    }
    for (int x : toplist) {
        char ch = x + 'A' - 1;
        cout << ch << " ";
    }
    cout << endl;
    return 0;
}


/*
Input:
6 6
A C
A D
B D
B E
C F
D F

Output:
A B C D E F
Time Complexity: O(V + E)
Space Complexity: O(V + E)



*/