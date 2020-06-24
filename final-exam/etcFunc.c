//
//  etcFunc.c
//  finalexam
//
//  Created by wonjunlee on 2020/06/23.
//  Copyright © 2020 wonjun. All rights reserved.
//

#include "etcFunc.h"

void printGuide1(){
    printf("[i] Choice base menu\n");
    printf("[i] Menu 1. Read from file.\n");
    printf("[i] Other menu. Don\'t read from file.\n");
    printf("[i] If you choose \'1\' and no contents in file, error will happen.\n");
}

void printGuide2(){
    printf("\n\n[i] This is library program.\n");
    printf("[i] Menu 1. Add book information.\n");
    printf("[i] Menu 2. Update book information.\n");
    printf("[i] Menu 3. Delete book information.\n");
    printf("[i] Menu 4. Search book information.\n");
    printf("[i] Menu 5. Display book information.\n");
    printf("[i] Menu 6. Add author information.\n");
    printf("[i] Menu 7. Update author information.\n");
    printf("[i] Menu 8. Delete author information.\n");
    printf("[i] Menu 9. Search author information.\n");
    printf("[i] Menu 0. Exit\n");
    printf("[i] Book\'s id should be number and unique and can not be a negative number.\n");
}

int isEmpty(int n){
    if(n==0){
        return 1;
    }
    return 0;
}

int isFull(int n){
    if(n>=100){
        return 1;
    }
    return 0;
}

void getMenu(int *menu){
    printf("[+] Enter menu : ");
    scanf("%d", menu);
}

void getBookId(int *bookId){
    printf("[+] Enter book id : ");
    scanf("%d", bookId);
}

void getAuthorName(char* authorName){
    printf("[+] Enter author name : ");
    fflush(stdin);
    gets(authorName);
}
