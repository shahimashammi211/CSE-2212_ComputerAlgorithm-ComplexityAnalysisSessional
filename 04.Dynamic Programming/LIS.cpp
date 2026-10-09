#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n), dp(n, 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}

/*
Input
8
10 9 2 5 3 7 101 18

Output
4

Time: O(n²)
Space: O(n)

*/