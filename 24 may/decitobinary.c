#include <stdio.h>
void decitobinary(int x){
    int rem,ans=0;
    int p=1;
    while(x!=0){
         rem=x%2;
         ans=ans+(p*rem);
         x=x/2;
         p=p*10;
    }
   printf("Binary no is %d",ans);
    }

int main(){
    decitobinary(78);
    return 0;
}


#include <stdio.h>
void binarytodeci(int x){
    int rem,ans=0;
    int p=1;
    while(x!=0){
         rem=x%10;
         ans=ans+(rem*p);
         x=x/10;
         p=p*2;
    }
   printf("Binary no is %d",ans);
    }

int main(){
    binarytodeci(1001110);
    return 0;
}