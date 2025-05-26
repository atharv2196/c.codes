#include <stdio.h>
int main(){
    int a=897;
printf("The No is %d",a);
    int z=0;
    for(int i=a;i>0;i=i/10){
        z=z+1;
    }//length copied
    int sum=0;
    for(int i=z;i>0;i--){
        int c=a%10;
        sum=sum+c;
        a=a/10;
    }//self
    printf("\nSum is %d",sum);
    return 0;
}