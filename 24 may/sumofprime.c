#include <stdio.h>

int isPrime(int n) {
    if (n <= 1) return 0; 
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0; 
    }
    return 1; 
}


int sum(int x) {
    int primesum = 0;
    for (int i = 2; i <= x; i++) {
        if (isPrime(i)) {
            primesum += i; 
        }
    }
    return primesum;
}

int main() {
    int a;
    printf("Enter the number: ");
    scanf("%d", &a);
    
    if (a < 2) {
        printf("No prime numbers less than 2.\n");
    } else {
        printf("The sum of prime numbers from 2 to %d is %d\n", a, sum(a));
    }
    return 0;
}