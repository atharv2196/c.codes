#include <stdio.h>
#include <math.h>
void targetfinder(int *arr,int n,int b,int a){
    int target = b;
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
            printf("Target %d square root %d found at index %d\n",a, target, mid);
            found = 1;
            break; 
        }

    if (!found) {
        printf("Target not found in the array.\n");
    }
    
}}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int a;
    printf("\n Enter Target square root You want to find :");
    scanf("%d",&a);
    int b=sqrt(a);
    targetfinder(arr,n,b,a);
    

    return 0;
}
