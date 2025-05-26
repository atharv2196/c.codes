#include <stdio.h>
void fillarray(int *arr, int x) {
    for (int i = 0; i < x; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }
}
void fisrtoccurence(int *arr, int x, int key) {
    for (int i = 0; i < x; i++) {
        if (arr[i] == key) {
            printf("First occurrence of %d is at index %d\n", key, i);
            return;
        }
    }
    printf("Element %d not found in the array\n", key);
}
void lastoccurence(int *arr, int x, int key) {
    for (int i = x - 1; i >= 0; i--) {
        if (arr[i] == key) {
            printf("Last occurrence of %d is at index %d\n", key, i);
            return;
        }
    }
    printf("Element %d not found in the array\n", key);
}
int main() {
    int x;
    printf("How many elements do you want in the array: ");
    scanf("%d", &x);
    int arr[x];
    
    fillarray(arr, x);
    
    int key;
    printf("Enter the key to find its first and last occurrence: ");
    scanf("%d", &key);
    
    fisrtoccurence(arr, x, key);
    lastoccurence(arr, x, key);
    
    return 0;
}