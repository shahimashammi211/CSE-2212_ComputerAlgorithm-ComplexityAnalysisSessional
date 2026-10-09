#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, amount;
    cin >> n;
    int coin[100];
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    cin >> amount;
    int dp[10000] = {};
    for (int i = 1; i <= amount; i++) {
        dp[i] = 1000000;
    }
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coin[j] <= i) {
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
            }
        }
    }
    if (dp[amount] == 1000000)
        cout << "not possible" << endl;
    else
        cout << "minimum coin: " << dp[amount] << endl;
    return 0;
}

/*
Input:
3
1 2 5
11

Output:
minimum coin: 3

Algorithm:Dynamic Programming
Time: O(n × amount)
Space: O(amount)

*/