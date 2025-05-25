// Online C compiler to run C program online
#include <stdio.h>
void fillarray(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("Enter Element %d ::",i+1);
        scanf("%d",&arr[i]);
    }
}

void large(int *arr,int n,int x){
    x=arr[0];
    for(int i=0;i<=n;i++){
        if(arr[i]>x){
            x=arr[i];
        }
    
}
printf("\nThe Largest Element is %d .",x);
}

int main() {
    // Write C code here
    int n;
    printf("Enter No of Element You want in array :");
    scanf("%d",&n);
    int arr[n];
    int x;
    fillarray(arr,n);
    large(arr,n,x);
    

    return 0;
}