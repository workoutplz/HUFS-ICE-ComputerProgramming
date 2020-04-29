#include <stdio.h>
int main(void) {
    int number, tmp, result, i;
    i = 1;
    result = 0;
    
    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &number);

    do {
        tmp = number % 8;
        result += tmp * i;
        number = number / 8;
        i *= 10;
    } while (number > 0);

    printf("\n In octal, your number is: %05d\n", result);
    return 0;
}