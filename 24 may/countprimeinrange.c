#include <stdio.h>
int isprime(int y){
    if(y<=1) return 0;
    for(int i=2;i*i<=y;i++){
        if(y%i==0) return 0;
        
    }
    return 1;
}
void count(int x,int y,int c){
     for(int i=x;i<=y;i++){
    if(isprime(i)){
    c++;
    }
}
printf("The Total No of Prime No in Range %d to %d is, %d",x,y,c);
    
}
void dispprime(int x,int y){
    for(int i=x;i<=y;i++){
    if(isprime(i)){
        printf("%d\t",i);
    }
}
    
}
int main() {
int x;
printf("Enter Starting No:");
scanf("%d",&x);
int y;
printf("Enter Ending No:");
scanf("%d",&y);
printf("The Prime No are :\n");
int c=0;
dispprime(x,y);
printf("\n");
count(x,y,c);

    return 0;
}