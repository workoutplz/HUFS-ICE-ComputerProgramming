/*
    HUFS 202002599 Wonjun Lee (Information Communications Engineering)
*/

#include<stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    
    int result = 3*x*x*x*x*x + 2*x*x*x*x - 5*x*x*x - x*x + 7*x - 6;
    printf("%d\n", result);

    return 0;
}