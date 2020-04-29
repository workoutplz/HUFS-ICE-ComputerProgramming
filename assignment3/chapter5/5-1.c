//5-1
#include <stdio.h>

int main() {
    int number = 0;
    printf("Enter a number : ");
    scanf("%d", &number);


    if(number/1000 > 0) {
        printf("The number %d has 4 digits\n", number);
    } else if(number/100 > 0) {
        printf("The number %d has 3 digits\n", number);
    }else if(number/10 > 0) {
        printf("The number %d has 2 digits\n", number);
    }else {
        printf("The number %d has 1 digits\n", number);
    }

    return 0;
}