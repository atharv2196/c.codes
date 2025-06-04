#include <stdio.h>
#include <stdbool.h>
void bubbleSort(int *arr, int n) {
    bool iswap;

    for (int i = 0; i < n - 1; i++) {
        iswap = false;  // Reset for this pass

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                iswap = true;
            }
        }

        if (!iswap) {
            // No swaps happened — already sorted
            return;
        }
    }
}
//time complexity: O(n^2) in the worst case, O(n) in the best case
//space complexity: O(1) as it sorts in place   
//working: The algorithm repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the
//compare if adjacent elements is repeated until the list is sorted. The algorithm gets its name from the way smaller elements "bubble" to the top of the list.