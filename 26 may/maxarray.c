#include <stdio.h>
void fillarray(int *arr, int x) {
    for (int i = 0; i < x; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }
}

void maxarray(int *arr, int x) {
    int max = arr[0];
    for (int i = 1; i < x; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Maximum element in the array is: %d\n", max);
}
void minarray(int *arr, int x) {
    int min = arr[0];
    for (int i = 1; i < x; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("Minimum element in the array is: %d\n", min);
}
int main() {
    int x;
    printf("How many elements do you want in the array: ");
    scanf("%d", &x);
    int arr[x];
    
    fillarray(arr, x);
    
    maxarray(arr, x);
    minarray(arr, x);
    
    return 0;
}