// Online C compiler to run C program online
#include <stdio.h>
int isprime(int x){
    if(x<=1) return 0;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return 0;
        
    }
    return 1;
}
void array(int x,int *arr){
    int p=0;
    for(int i=2;i<=x;i++){
        if(isprime(i)){
            arr[p]=i;
              p++;
        }
      
        
    }
}

void dispprime(int x){
    for(int i=2;i<=x;i++){
    if(isprime(i)){
        printf("%d\t",i);
    }
}
    
}
int main() {
int a=100;
int n;

int arr[25]={0};
printf("The Prime No are :");
dispprime(a);
array(a,arr);

printf("\nYou prime Number at which Number:");
scanf("%d",&n);
printf("Prime Number at Position %d is %d",n,arr[n-1]);

    return 0;
}