#include <stdio.h>


int main() {
    int a = 121;
    int z = 0;
    for (int i = a; i > 0; i = i / 10) {
        z++;
    }//length copied

    int digits[z];
    int arr = a;
    for (int i = z-1; i >=0; i--) {
        digits[i] = arr % 10;
        arr = arr / 10;
    }//convert to array

    int p = 1;  //checkiing var or flag

    for (int i = 0; i < z; i++) {
        for (int j = z  -1- i; j == z  -1- i; j--) {
            if (digits[i] != digits[j]) {
                p = 0;
            }
        }
    }

    if (p == 1) {
        printf("%d is Palindrome\n", a);
    } else {
        printf("%d is not Palindrome\n", a);
    }

    return 0;
}
