//5-5
#include <stdio.h>

int main() {
    float income, tax;

    printf("Enter income : ");
    scanf("%f", &income);

    if(income < 750) {
        tax = income + income*0.01;
        printf("tax is 1%% of income : %.2f\n", tax);
    } else if(income < 2250) {
        tax = income + 7.50 + (income-750)*0.02;
        printf("tax is $7.50 and plus 2%% of amount over $750 : %.2f\n", tax);
    } else if(income < 3750) {
        tax = income + 37.50 + (income-2250)*0.03;
        printf("tax is $37.50 and plus 3%% of amount over $2,250 : %.2f\n", tax);
    } else if(income < 5250) {
        tax = income + 82.50 + (income-3750)*0.04;
        printf("tax is $82.50 and plus 4%% of amount over $3,750 : %.2f\n", tax);
    } else if(income < 7000) {
        tax = income + 142.50 + (income-5250)*0.05;
        printf("tax is $142.50 and plus 5%% of amount over $5,250 : %.2f\n", tax);
    } else {
        tax = income + 230.00 + (income-7000)*0.06;
        printf("tax is $230.00 and plus 6%% of amount over $7,000 : %.2f\n", tax);
    }

    return 0;
}