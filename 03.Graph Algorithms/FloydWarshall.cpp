#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int dist[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    cout << "Shortest Distance :" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
Input:
4
0 5 10 15
5 0 3 9
10 3 0 1
15 9 1 0

Output:
Shortest Distance Matrix:
0 5 8 9
5 0 3 4
8 3 0 1
9 4 1 0

Time Complexity: O(V³)
Space Complexity: O(V²)

*/