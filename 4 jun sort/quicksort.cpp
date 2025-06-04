#include <iostream>
using namespace std;

// Function to partition the array and place pivot correctly
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivot element (last element)
    int i = low - 1;        // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);  // Swap elements smaller than pivot
        }
    }

    swap(arr[i + 1], arr[high]);  // Place pivot in correct position
    return i + 1;  // Return partition index
}

// Recursive function to apply quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Partition index

        quicksort(arr, low, pi - 1);   // Sort left half
        quicksort(arr, pi + 1, high);  // Sort right half
    }
}

// Main function to test quicksort
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
// Time complexity: O(n log n) on average, O(n^2) in the worst case
// Space complexity: O(log n) due to recursive stack space  