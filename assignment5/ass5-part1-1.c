//ass5 part1 1
#include<stdio.h>

int main() {
    int size1, size2, cnt, tmpSize = 0;
    printf("Enter first set size : ");
    scanf("%d", &size1);

    printf("Enter second set size : ");
    scanf("%d", &size2);

    int arr1[size1], arr2[size2];

    if (size1 > size2) {
        tmpSize = size1;
    } else {
        tmpSize = size2;
    }

    int tmp[tmpSize];

    for(int i=0; i<size1; i++) {
        printf("Enter %d in first set : ", i+1);
        scanf("%d", &arr1[i]);
    }

    for(int i=0; i<size2; i++) {
        printf("Enter %d in second set : ", i+1);
        scanf("%d", &arr2[i]);
    }

    for(int i=0; i<tmpSize; i++) {
        for(int j=0; j<tmpSize; j++) {
            if(arr1[i] == arr2[j]) {
                for(int k=0; k<cnt+1; k++) {
                    if(tmp[k] == arr1[i]) {
                    } else {
                        tmp[cnt++] = arr1[i];
                        break;
                    }
                }
                break;
            }
        }
    }

    int result[cnt], temp;

    for(int i=0; i<cnt; i++) {
        result[i] = tmp[i];
    }
    temp = result[0];

    for(int i=0; i<cnt; i++) {
        for(int j=0; j<cnt-i-1; j++) {
            if(result[j] > result[j+1]) {
                temp = result[j];
                result[j] = result[j+1];
                result[j+1] = temp;
            }
        }
    }

    printf("Intersection of two sets : ");

    for(int i=0; i<cnt; i++) {
        printf("%d ", result[i]);
    }
}