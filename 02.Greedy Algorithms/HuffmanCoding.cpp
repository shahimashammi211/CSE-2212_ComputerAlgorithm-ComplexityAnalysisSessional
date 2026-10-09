#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    char ch[100];
    int freq[100];
    for (int i = 0; i < n; i++) {
        cin >> ch[i] >> freq[i];
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        pq.push(freq[i]);
    }
    int cost = 0;
    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int sum = a + b;
        cost += sum;
        pq.push(sum);
    }
    cout << "Minimum Cost: " << cost << endl;
    return 0;
}
/*
Input:
5
A 5
B 9
C 12
D 13
E 16

Output:
Minimum Cost: 124

Time Complexity: O(n log n)
Space Complexity: O(n)

*/
