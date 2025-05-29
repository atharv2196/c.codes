#include <stdio.h>
void targetfinder(int *arr,int n,int a){
    int target = a;
    int st = 0, end = n - 1;
    int mid;
    int found = 0;

    while (st <= end) {
        mid = st + (end - st) / 2;
        

        if(arr[mid]==target){
            printf("\nTarget %d found at %d",target,mid);
            found=1;
        }
        if(arr[st]<=mid){//left sorted
        
        if(arr[st]<=target && target<=arr[mid]){
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    else{
        if(arr[mid]<=target && target<=arr[end]){
            st=mid+1;
        }
        else{
            end=mid-1;
        }
        }
        }
        
    }
    




int main() {
    int arr[] = {7,8,9,10,1,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int a;
    printf("\n Enter Target You want to find :");
    scanf("%d",&a);
    targetfinder(arr,n,a);
    

    return 0;
}
