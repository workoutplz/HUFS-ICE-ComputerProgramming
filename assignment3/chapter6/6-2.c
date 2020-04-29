//6-2
#include<stdio.h>

int main() {
    int number1, number2, gcd = 0;
    printf("Enter two integers : ");
    scanf("%d %d", &number1, &number2);

    for(int i=1; i<=number1; i++) {
        if(number1%i==0 && number2%i==0) {
            gcd = i;
        }
    }

    printf("Greatest common divisor: %d\n", gcd);
    return 0;
}