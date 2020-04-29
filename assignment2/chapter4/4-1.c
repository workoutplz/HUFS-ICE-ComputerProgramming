#include <stdio.h>

int main(void) {
    int number;

    printf("Enter a two-digit number:");
    scanf("%d", &number);
    
    printf("The reversal is: ");
    
    do {
        printf("%d", number % 10);
        number = number / 10;
    } while(number);
    
    printf("\n");
    return 0;
}
