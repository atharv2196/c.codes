// Online C compiler to run C program online
#include <stdio.h>
void fillarray(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("Enter Element %d ::",i+1);
        scanf("%d",&arr[i]);
    }
}
void count(int *arr,int n){
    int even=0;
    int odd=0;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            even++;
        }   
        else {
            odd++;
        }}
printf("\nThe no of Even  Element is %d .",even);
printf("\nThe no of odd  Element is %d .",odd);
}
int main() {
    // Write C code here
    int n;
    printf("Enter No of Element You want in array :");
    scanf("%d",&n);
    int arr[n];
    int x;
    fillarray(arr,n);
    count(arr,n);
    return 0;
}