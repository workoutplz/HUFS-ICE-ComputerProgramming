/*
    HUFS 202002599 Wonjun Lee (Information Communications Engineering)
*/

#include<stdio.h>

#define TAX 0.05

int main() {
    float money;

    printf("Enter an amount : ");
    scanf("%f", &money);
    
    float result = money + money * TAX;
    printf("With tax added : $%f\n", result);
    
    return 0;
}