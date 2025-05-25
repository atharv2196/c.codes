#include <stdio.h>
void fillarray(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("Enter Element %d ::",i+1);
        scanf("%d",&arr[i]);
    }
}
void reverse(int *arr,int n,int *rev){
    for(int i=0;i<n;i++){
         rev[i] = arr[n - 1 - i]; 
        }   
                }
void disprev(int *rev,int n){
    for(int i=0;i<n;i++){
        printf("\nrev Element %d is %d",i+1,rev[i]);
    }
}
int main() {
    // Write C code here
    int n;
    printf("Enter No of Element You want in array :");
    scanf("%d",&n);
    int arr[n];
    int rev[n];
    
    fillarray(arr,n);
    reverse(arr,n,rev);
    disprev(rev,n);
    return 0;
}