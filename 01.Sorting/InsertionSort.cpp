#include <bits/stdc++.h>
using namespace std;
void insertion_sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main() {
    int arr[] = {9, 5, 2, 7, 4, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}

/*
Input
9 5 2 7 4 3 1
 Output
1
2
3
4
5
7
9

Time Complexity: O(n2)
Space Complexity: O(1)
*/