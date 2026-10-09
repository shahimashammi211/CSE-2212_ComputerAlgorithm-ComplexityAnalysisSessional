#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int zero_one_knapsack(int n, int k, int weight[], int profit[]) {
    vector<vector<int>> mat(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (i == 0 || j == 0) {
                mat[i][j] = 0;
            }
            else if (j >= weight[i - 1]) {
                mat[i][j] = max(
                    profit[i - 1] + mat[i - 1][j - weight[i - 1]],
                    mat[i - 1][j]
                );
            }
            else {
                mat[i][j] = mat[i - 1][j];
            }
        }
    }
    int i = n, j = k;
    while (i > 0 && j > 0) {
        if (mat[i][j] != mat[i - 1][j]) {
            v.push_back(i - 1);
            j -= weight[i - 1];
        }
        i--;
    }
    reverse(v.begin(), v.end());
    return mat[n][k];
}
int main() {
    int w[] = {1, 3, 5, 8, 10};
    int p[] = {7, 12, 15, 18, 20};
    int n = sizeof(w) / sizeof(w[0]);
    int knapsack = 7;
    int maxprofit = zero_one_knapsack(n, knapsack, w, p);
    cout << "Max Profit: " << maxprofit << "\n";
    cout << "Selected item (0-based index):\n";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

/*
Output:
7
Algorithm:
0/1 Knapsack — Dynamic Programming
Complexity:
Time Complexity: O(n × W)
Space Complexity: O(n × W)
Here, n is the number of items and W is the knapsack capacity.

*/