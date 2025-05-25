#include <stdio.h>
void fillarray(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("Enter Element %d ::",i+1);
        scanf("%d",&arr[i]);
    }
}
int isprime(int num) {
    if(num < 2) return 0;
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0)
            return 0;
    }
    return 1;
}
void isprimearr(int *arr,int n,int *prime,int *x){
    *x=0;
    for(int i=0;i<n;i++){
        if(isprime(arr[i])){
            prime[*x]=arr[i];
            (*x)++;
        }
    }
}

void disprime(int *prime,int x){
    int a=0;
    printf("\nPrime No are: ");
    for(int i=0;i<x;i++){
        printf("%d\t",prime[i]);
        a++;
    }
    printf("\n\nNo of Prime No are %d",a);
}


int main() {
    int n;
    printf("Enter No of Element You want in array :");
    scanf("%d",&n);
    int arr[n];
    int prime[n];
    int x;
    fillarray(arr,n);
    isprimearr(arr,n,prime,&x);
    disprime(prime,x);
    return 0;
}