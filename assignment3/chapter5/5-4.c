//5-4
#include <stdio.h>

int main() {
    int speed;

    printf("Enter a wind spped : ");
    scanf("%d", &speed);

    if(speed<1) {
        printf("Calm\n");
    } else if(speed <= 3) {
        printf("Light air\n");
    } else if(speed <= 27) {
        printf("Breeze\n");
    } else if(speed <= 47) {
        printf("Gale\n");
    } else if(speed <= 63) {
        printf("Storm\n");
    } else {
        printf("Hurricane\n");
    }

    return 0;
}