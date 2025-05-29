#include <stdio.h>

// Function to find first and last occurrence of a target element in sorted array
void targetfinder(int *arr, int n, int target) {
    int first = -1, last = -1; // These will hold the index of first and last occurrence
    int st, end, mid;          // Binary search pointers: start, end, middle

    // --------- First Occurrence ---------
    st = 0;
    end = n - 1;

    while (st <= end) {
        mid = st + (end - st) / 2;  // Avoid overflow

        if (arr[mid] > target) {
            // If mid element is greater, search in left half
            end = mid - 1;
        } else if (arr[mid] < target) {
            // If mid element is smaller, search in right half
            st = mid + 1;
        } else {
            // If mid element matches target, store index
            first = mid;
            // But continue searching in left half for earlier occurrence
            end = mid - 1;
        }
    }

    // --------- Last Occurrence ---------
    st = 0;
    end = n - 1;

    while (st <= end) {
        mid = st + (end - st) / 2;

        if (arr[mid] > target) {
            // Target is on the left side
            end = mid - 1;
        } else if (arr[mid] < target) {
            // Target is on the right side
            st = mid + 1;
        } else {
            // Found target, store index
            last = mid;
            // But continue searching in right half for later occurrence
            st = mid + 1;
        }
    }

    // --------- Output Result ---------
    if (first != -1 && last != -1) {
        // Target was found in the array
        printf("Target %d found.\n", target);
        printf("First occurrence at index %d\n", first);
        printf("Last occurrence at index %d\n", last);
    } else {
        // Target was not found
        printf("Target %d not found in the array.\n", target);
    }
}

int main() {
    // Sorted array (can contain duplicates)
    int arr[] = {1, 2, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]); // Total number of elements in array
    int a;

    // Ask user to enter target value
    printf("Enter target you want to find: ");
    scanf("%d", &a);

    // Call function to find target
    targetfinder(arr, n, a);

    return 0;
}
