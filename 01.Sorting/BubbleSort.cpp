#include <bits/stdc++.h>
using namespace std;
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}
int main() {
    int arr[] = {9, 5, 2, 7, 4, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}
/*
Input
9 5 2 7 4 3 1
Output
9
7
5
4
3
2
1

Time Complexity:
Best case O(n),
average,worst case O(n2)
Space Complexity: O(1)
*/