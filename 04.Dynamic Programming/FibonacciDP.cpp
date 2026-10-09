#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int dp[1000];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << "fibonacci: " << dp[n] << endl;
    return 0;
}
/*
Input:
7

Output:
fibonacci: 13

Time: O(n)
Space: O(n)

*/