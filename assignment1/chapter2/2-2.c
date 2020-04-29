/*
    HUFS 202002599 Wonjun Lee (Information Communications Engineering)
*/

#include <stdio.h>

#define PI 3.14
#define FRACTION (4.0f/3.0f)

int main() {
    float radius = 10;
    float volume = FRACTION * radius * radius * radius * PI;

    printf("%f", volume);
    
    return 0;
}