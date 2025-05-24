#include <stdio.h>

int main()
{

for(int i=2;i<=100;i++){
    int z=0;
    for(int j=1;j<=i;j++){
        if(i%j==0){
            z=z+1;
        }
        
        
    }
    if(z==2){
            printf("%d\t",i);
        }
}

    return 0;
}

#include <stdio.h>
int isprime(int x){
    if(x<=1) return 0;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return 0;
        
    }
    return 1;
}

int main() {
int a=100;
for(int i=0;i<=a;i++){
    if(isprime(i)){
        printf("%d\t",i);
    }
}
    return 0;
}

// also
// #include <stdio.h>
// int isprime(int i){
//     for(int j=2;j<i;j++){
//         if(i%j==0){
//         return j;
//         }
        
        
//         }
        
//     }

// int main()
// {
// for(int i=0;i<=100;i++){
//     printf("%d ",isprime(i));
    
    
// }
//     return 0;
// }