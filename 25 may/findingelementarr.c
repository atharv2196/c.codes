#include <stdio.h>
void fillarray(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("Enter Element %d ::",i+1);
        scanf("%d",&arr[i]);
    }
}

void find(int *arr,int n,int x){
    int found=0;
    for(int i=0;i<=n;i++){
        
        if(arr[i]==x){
           printf("Element %d Found at position %d",x,i+1);
           found=1;
           
           }
           
        
         }
         if(found==0){
             printf("\nElement not Found ");
         }
         
}


int main() {
    // Write C code here
    int n;
    printf("Enter No of Element You want in array :");
    scanf("%d",&n);
    int arr[n];
    int x;
    printf("You Want to seach element :");
    scanf("%d",&x);
    fillarray(arr,n);
    find(arr,n,x);
    

    return 0;
}