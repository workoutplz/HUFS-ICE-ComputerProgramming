//ass5 part1 2
#include<stdio.h>

int main() {
    int size1, size2, cnt;
    printf("Enter first set size : ");
    scanf("%d", &size1);

    printf("Enter second set size : ");
    scanf("%d", &size2);

    int arr1[size1], arr2[size2];

    int tmp[size1 + size2];
    int tmpIndex = 0;

    for(int i=0; i<size1; i++) {
        printf("Enter %d in first set : ", i+1);
        scanf("%d", &arr1[i]);
    }

    for(int i=0; i<size2; i++) {
        printf("Enter %d in second set : ", i+1);
        scanf("%d", &arr2[i]);
    }

    for(int i=0; i<size1; i++){
        int flag = 0;
        for(int j=0;j<tmpIndex;j++)
            if(arr1[i] == tmp[j]){
                flag = 1;
                break;
            }
        if(!flag)
            tmp[tmpIndex++] = arr1[i];
    }

    for(int i=0; i<size2; i++){
        int flag = 0;
        for(int j=0;j<tmpIndex;j++)
            if(arr2[i] == tmp[j]){
                flag = 0;
                break;
            }
        if(!flag)
            tmp[tmpIndex++] = arr2[i];
    }



    printf("Union of two sets : ");

    for(int i=0; i<tmpIndex; i++)
        printf("%d ", tmp[i]);
}