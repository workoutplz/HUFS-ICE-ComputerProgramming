//5-10
#include <stdio.h>

int main() {
    int score = 0;
    printf("Enter numerical grade : ");
    scanf("%d", &score);

    printf("Leeter grade : ");
    int grade = score / 10;
    switch(grade) {
        case 10:
            printf("A\n");
            break;
        case 9:
            printf("A\n");
            break;
        case 8:
            printf("B\n");
            break;
        case 7:
            printf("C\n");
            break;
        case 6:
            printf("D\n");
            break;
        default:
            printf("F\n");
            break;
    }
}
