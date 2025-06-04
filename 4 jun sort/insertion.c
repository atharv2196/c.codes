#include <stdio.h>

void insertionsort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int curr = arr[i];       // 'curr' is the current key to be inserted into the sorted part
        int prev = i - 1;        // 'prev' is the index of the previous element

        // Move elements of arr[0..i-1] that are greater than curr
        // to one position ahead of their current position
        while (prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];  // Shift the element to the right
            prev--;                     // Move to the previous element
        }

        arr[prev + 1] = curr;   // Place 'curr' at its correct sorted position
    }
}
// Time complexity: O(n^2) in the worst case, O(n) in the best case
// Space complexity: O(1) as it sorts in place      
// Working: The algorithm builds a sorted array one element at a time. It takes each element from the input and finds its correct position in the already sorted part of the array.