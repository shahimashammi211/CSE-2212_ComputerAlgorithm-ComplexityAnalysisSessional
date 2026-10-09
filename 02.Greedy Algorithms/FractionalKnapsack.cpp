#include <bits/stdc++.h>
using namespace std;
struct product {
    int weight;
    double profit;
    double unit_profit;
};
bool cmp(product a, product b) {
    return a.unit_profit > b.unit_profit;
}
double fractional_knapsack(int n, int knapsack, product prod[]) {
    sort(prod, prod + n, cmp);
    double profit = 0;
    for (int i = 0; i < n; i++) {
        if (knapsack >= prod[i].weight) {
            knapsack -= prod[i].weight;
            profit += prod[i].profit;
        }
        else {
            profit += knapsack * prod[i].unit_profit;
            break;
        }
    }
    return profit;
}
int main() {
    int w[] = {7, 5, 4, 3, 2};
    double p[] = {15, 10, 20, 14, 12};
    int n = sizeof(w) / sizeof(w[0]);
    int knapsack = 11;
    product prod[n];
    for (int i = 0; i < n; i++) {
        prod[i].weight = w[i];
        prod[i].profit = p[i];
        prod[i].unit_profit = p[i] / w[i];
    }
    double maxprofit = fractional_knapsack(n, knapsack, prod);
    cout << maxprofit << endl;
    return 0;
}

/*

Input:
Weights: 7 5 4 3 2
Profits: 15 10 20 14 12
Knapsack Capacity: 11
Output:
51
Greedy Algorithm
Time Complexity: O(n log n)
 Space Complexity: O(log n) typically, due to sorting recursion stack.

*/