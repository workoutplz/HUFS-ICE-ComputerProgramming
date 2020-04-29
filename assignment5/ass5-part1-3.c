//ass5 part1 3
#include<stdio.h>

int main() {
    int size, max = 0;
    printf("Enter a size : ");
    scanf("%d", &size);

    int arr[size];
    for(int i=0; i<size; i++) {
        printf("Enter %d number in array : ", i+1);
        scanf("%d", &arr[i]);
    }

    max = arr[0];

    for(int i=0; i<size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Largest element is %d\n", max);
}
