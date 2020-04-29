//6-3
#include<stdio.h>

int main() {
    int numerator, denominator, gcd = 0;
    printf("Enter a fraction : ");
    scanf("%d/%d", &numerator, &denominator);

    for(int i=1; i<=numerator; i++){
        if(numerator%i==0 && denominator%i==0) {
            gcd = i;
        }
    }

    numerator /= gcd;
    denominator /= gcd;

    printf("In lowest term : %d/%d\n", numerator, denominator);
    return 0;
}