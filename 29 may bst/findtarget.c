#include <stdio.h>
void targetfinder(int *arr,int n,int a){
    int target = a;
    int st = 0, end = n - 1;
    int mid;
    int found = 0;

    while (st <= end) {
        mid = st + (end - st) / 2;

        if (target < arr[mid]) {
            end = mid - 1;
        } 
        else if (target > arr[mid]) {
            st = mid + 1;
        }
        else {
            printf("Target %d found at index %d\n", target, mid);
            found = 1;
            break; 
        }

    if (!found) {
        printf("Target not found in the array.\n");
    }
    //9/2=4 no is 5
}}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int a;
    printf("\n Enter Target You want to find :");
    scanf("%d",&a);
    targetfinder(arr,n,a);
    

    return 0;
}
