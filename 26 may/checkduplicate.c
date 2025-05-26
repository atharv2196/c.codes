#include <stdio.h>

void fillarray(int *arr, int x) {
    for (int i = 0; i < x; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }
}
int hasDuplicates(int *arr, int x) {
    for (int i = 0; i < x; i++) {
        for (int j = i + 1; j < x; j++) {
            // If we find a match, it's a duplicate
            if (arr[i] == arr[j]) {
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    int x;
    printf("How many elements do you want in the array: ");
    scanf("%d", &x);
    int arr[x];
    fillarray(arr, x);
  
    if (hasDuplicates(arr, x)) {
        printf("array has duplicates\n");
    } else {
        printf("array has no duplicates\n");
    }
    
    
    
    return 0;
}