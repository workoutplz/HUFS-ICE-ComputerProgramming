//
//  bookFunc.c
//  finalexam
//
//  Created by wonjunlee on 2020/06/23.
//  Copyright © 2020 wonjun. All rights reserved.
//

#include "bookFunc.h"
#include <stdio.h>

int isIn(BOOK books[], int bookId){
    for(int i=0; i<bIdx; i++){
        if(books[i].bookId == bookId){
            return 1;
        }
    }
    return 0;
}

int isPositive(int bookId){
    if(bookId>0){
        return 1;
    } else {
        return 0;
    }
}

int isEffective(BOOK books[], int bookId){
    if(!isIn(books, bookId)&&isPositive(bookId)){
        return 1;
    } else {
        printf("[-] Invalid book id.\n");
        return 0;
    }
}

void enterBookInformation(BOOK books[], int idx){
    int bookId, flag = 1;
    if(bIdx==0){
        getBookId(&books[idx].bookId);
    }else{
        do {
            getBookId(&bookId);
            if(isEffective(books, bookId)){
                books[idx].bookId = bookId;
                flag = 0;
            }
        }while(flag);
    }
    printf("[+] Enter book\'s name : ");
    fflush(stdin);
    gets(books[idx].bookName);

    printf("[+] Enter book\'s publication date : ");
    fflush(stdin);
    gets(books[idx].publicationDate);

    printf("[+] Enter publisher\'s name : ");
    fflush(stdin);
    gets(books[idx].publisherName);
}

void addBookInformation(BOOK books[]){
    enterBookInformation(books, bIdx++);
}

int findBookIndex(BOOK books[], int bookId){
    for(int i=0; i<bIdx; i++){
        if(bookId == books[i].bookId){
            return i;
        }
    }
    return bIdx;
}

void deleteBookInformation(BOOK books[], int bookId){
    int idx = findBookIndex(books, bookId);
    if(idx==bIdx){
        printf("[-] Invalid book id.\n");
    } else {
        for(int i=idx; i<bIdx-1; i++){
            books[i] = books[i+1];
        }
        bIdx--;
    }
}

void updateBookInformation(BOOK books[], int bookId){
    int idx = findBookIndex(books, bookId);
    if(idx==bIdx){
        printf("[-] Invalid book id.\n");
    } else {
        enterBookInformation(books, idx);
    }
}

void printBookInformation(BOOK books[], int idx){
    printf("----------------------------------------\n");
    printf("[-] Book ID : %d\n", books[idx].bookId);
    printf("[-] Book name : ");
    puts(books[idx].bookName);
    printf("[-] Book publication date : ");
    puts(books[idx].publicationDate);
    printf("[-] Book publisher name : ");
    puts(books[idx].publisherName);
    printf("----------------------------------------\n");
}

void searchBookInformation(BOOK books[], int bookId){
    for(int i=0; i<bIdx; i++){
        if(bookId == books[i].bookId) {
            printBookInformation(books, i);
        }
    }
}

void displayBookInformation(BOOK books[]){
    for(int i=0; i<bIdx; i++) {
        printf("----------------------------------------\n");
        printf("[-] Book ID : %d\n", books[i].bookId);
        printf("[-] Book name : ");
        puts(books[i].bookName);
        printf("[-] Book publication date : ");
        puts(books[i].publicationDate);
        printf("[-] Book publisher name : ");
        puts(books[i].publisherName);
        printf("----------------------------------------\n");
    }
}

void printBookInformation2(BOOK book, int bookNumber){
    printf("[-] Book%d ID : %d\n", bookNumber, book.bookId);
    printf("[-] Book%d name : ", bookNumber);
    puts(book.bookName);
    printf("[-] Book%d publication date : ", bookNumber);
    puts(book.publicationDate);
    printf("[-] Book%d publisher name : ", bookNumber);
    puts(book.publisherName);
}
