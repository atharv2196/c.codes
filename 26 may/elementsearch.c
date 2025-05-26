#include <stdio.h>

void fillarray(int *arr,int x){
    for(int i=0;i<=x;i++){
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }

}
void keyfind(int *arr,int x,int key){
     int find=0;
     int i;
     for(i=0;i<=x;i++){
             if(arr[i]==key){
                             printf("\nelement %d Found at index %d",x,i);
                             find=1;}
             
             }
             if(find==0){
                         printf("Element not found");
                         }
                         }
int main(){
    int x;
    printf("How many element u want in array :");
    scanf("%d",&x);
    int arr[x];
    int key;
    printf("Enter key that u want to find :");
    scanf("%d",&key);
    fillarray(arr,x);
    keyfind(arr,x,key);
                     return 0;
                     }   
