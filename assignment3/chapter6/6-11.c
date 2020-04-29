//6-11
#include<stdio.h>

int main() {
    float number, result, fac = 1.00;
    printf("Enter a number : ");
    scanf("%f", &number);

    for(int i=1; i<=number; i++) {
        for(int j=1; j<=i; j++) {
            fac *= j;
        }
        result += 1/fac;
    }

    printf("%f\n", result+1);
    return 0;
}
