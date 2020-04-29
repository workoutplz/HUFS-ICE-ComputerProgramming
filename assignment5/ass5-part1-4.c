//ass5 part1 4
#include<stdio.h>

int main() {
    int size, min = 0;
    printf("Enter a size : ");
    scanf("%d", &size);

    int arr[size];
    for(int i=0; i<size; i++) {
        printf("Enter %d number in array : ", i+1);
        scanf("%d", &arr[i]);
    }

    min = arr[0];

    for(int i=0; i<size; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    printf("Smallest element is %d\n", min);
}