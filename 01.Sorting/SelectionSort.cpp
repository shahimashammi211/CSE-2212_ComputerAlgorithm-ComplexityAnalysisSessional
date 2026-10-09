#include <bits/stdc++.h>
using namespace std;
void selectionsort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
int main() {
    int arr[] = {9, 5, 2, 7, 4, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionsort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " " << endl;
    }
    return 0;
}
/*1
2
3
4
5
7
9

Time Complexity
Best Case
O(n2)
Average Case
O(n2)
Worst Case
O(n2)
Space Complexity
O(1)
*/