//5-7
#include <stdio.h>

int main() {
    int number1, number2, number3, number4, tmp = 0;

    printf("Enter four ingers : ");
    scanf("%d %d %d %d", &number1, &number2, &number3, &number4);

    int numbers[4] = {number1, number2, number3, number4};

    for(int i=0; i<3; i++) {
        for(int j=i+1; j<4; j++) {
            if(numbers[i] > numbers[j]) {
                numbers[i] = tmp;
                numbers[i] = numbers[j];
                numbers[j] = tmp;
            }
        }
    }

    printf("Largest : %d\n", numbers[3]);
    printf("Smallest : %d\n", numbers[0]);

    return 0;
}