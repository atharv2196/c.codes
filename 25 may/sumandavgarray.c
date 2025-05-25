#include <stdio.h>
void fillarray(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("Enter Element %d ::",i+1);
        scanf("%d",&arr[i]);
    }
}
void sum(int *arr,int n,int total){
    total=0;
    for(int i=0;i<=n;i++){
        total=total+arr[i];
        }
printf("\nThe Sum of Element is %d .",total);
float avg=total/n;
printf("\nThe Average is %.3f",avg);
}

int main() {
    // Write C code here
    int n;
    printf("Enter No of Element You want in array :");
    scanf("%d",&n);
    int arr[n];
    int x;
    fillarray(arr,n);
    sum(arr,n,x);
    

    return 0;
}