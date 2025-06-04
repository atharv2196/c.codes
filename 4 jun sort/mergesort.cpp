#include <stdio.h>

// Function to merge two sorted halves
void merge(int arr[], int left, int mid, int right) {
    int i = left;       // Starting index of left subarray
    int j = mid + 1;    // Starting index of right subarray
    int k = 0;          // Index for temp array

    int temp[right - left + 1];  // Temporary array to hold merged result

    // Merge both halves into temp[]
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements of left subarray (if any)
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements of right subarray (if any)
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy sorted elements back to original array
    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}

// Recursive function to divide the array
void mergesort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergesort(arr, left, mid);       // Sort left half
        mergesort(arr, mid + 1, right);  // Sort right half

        merge(arr, left, mid, right);    // Merge the two sorted halves
    }
}
//recursive function to sort the array using merge sort