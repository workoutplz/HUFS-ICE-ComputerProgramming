/*
    HUFS 202002599 Wonjun Lee (Information Communications Engineering)
*/

#include<stdio.h>

int main() {
    int amount;
    printf("Enter a dollor amount : ");
    scanf("%d", &amount);

    int quotientOf20 = amount / 20;
    int remainderOf20 = amount % 20;
    
    int quotientOf10 = remainderOf20 / 10;
    int remainderOf10 = remainderOf20 % 10;
    
    int quotientOf5 = remainderOf10 / 5;
    int remainderOf5 = remainderOf10 % 5;
    int quotientOf1 = remainderOf5 / 1;
    
    printf("$20 bills: %d\n", quotientOf20);
    printf("$10 bills: %d\n", quotientOf10);
    printf(" $5 bills: %d\n", quotientOf5);
    printf(" $1 bills: %d\n", quotientOf1);

    return 0;
}