#include <bits/stdc++.h>
using namespace std;
int arr[] = {0, 1, 2, 3, 9, 1, 7, 4, 3};
int n = (sizeof(arr) / sizeof arr[0]);
int ans[100];
void merge(int l, int mid, int H) {
    int L1 = l;
    int L2 = mid + 1;
    int i = l;
    while (L1 <= mid && L2 <= H) {
        if (arr[L1] < arr[L2]) {
            ans[i++] = arr[L1++];
        }
        else {
            ans[i++] = arr[L2++];
        }
    }
    while (L1 <= mid) {
        ans[i++] = arr[L1++];
    }
    while (L2 <= H) {
        ans[i++] = arr[L2++];
    }
    for (int i = l; i <= H; i++) {
        arr[i] = ans[i];
    }
}
void mergesort(int l, int H) {
    if (l < H) {
        int mid = (l + H) / 2;
        mergesort(l, mid);
        mergesort(mid + 1, H);
        merge(l, mid, H);
    }
}
int main() {
    mergesort(0, n - 1);
    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}
/*
Input
0, 1, 2, 3, 9, 1, 7, 4, 3
 Output
0 1 1 2 3 3 4 7 9
Time Complexity:
  Best Case:    O(n log n)
  Average Case: O(n log n)
  Worst Case:   O(n log n)
Space Complexity: O(n)
Approach: Divide and Conquer
Sorting Order: Ascending
*/