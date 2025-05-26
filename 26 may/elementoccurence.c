#include <stdio.h>

void fillarray(int *arr,int x){
    for(int i=0;i<=x;i++){
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }

}
void keycount(int *arr,int x,int key){
   
     int find=0;
    
     int i;
     for(i=0;i<=x;i++){
             if(arr[i]==key){
                            //arr[0]
                             find++;
                            }
             
             }
             printf("\nElement %d occured %d times ",key,find);
             
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
    keycount(arr,x,key);
                     return 0;
                     }   
