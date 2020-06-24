//
//  authorFunc.c
//  finalexam
//
//  Created by wonjunlee on 2020/06/23.
//  Copyright © 2020 wonjun. All rights reserved.
//

#include "authorFunc.h"

void getBook(AUTHOR *author, BOOK books[], int wBookId, int i){
    for(int j=0; j<bIdx; j++){
        if(books[j].bookId == wBookId){
            author->writtenBooks[i] = books[j];
        }
    }
}

int findAuthorIndex(AUTHOR authors[], char* authorName){
    for(int i=0; i<aIdx; i++){
        if(!strcmp(authors[i].authorName, authorName)){
            return i;
        }
    }
    return aIdx;
}

void enterAuthorInformation(AUTHOR authors[], int idx, BOOK books[]){
    int wBookId, i = 0;
    
    printf("[+] Enter author\'s name : ");
    fflush(stdin);
    gets(authors[idx].authorName);

    printf("[+] Enter author\'s email : ");
    fflush(stdin);
    gets(authors[idx].authorEmail);

    printf("[+] Enter author\'s phone number : ");
    fflush(stdin);
    gets(authors[idx].authorPhone);
    
    printf("[+] Enter author\'s address : ");
    fflush(stdin);
    gets(authors[idx].authorAddress);
    
    printf("[+] Enter author\'s biography : ");
    fflush(stdin);
    gets(authors[idx].authorBiography);
    
    printf("[+] Enter number of author\'s books : ");
    scanf("%d", &authors[idx].writtenBookNumber);

    while(i<authors[idx].writtenBookNumber){
        printf("[+] Enter id of author\'s book : ");
        scanf("%d", &wBookId);
        if(!isIn(books, wBookId) || wBookId<=0){
            printf("[-] Invalid book id. Try again.\n");
        } else {
            getBook(&authors[idx], books, wBookId, i);
            i++;
        }
    }
}

void addAuthorInformation(AUTHOR authors[], BOOK books[]){
    enterAuthorInformation(authors, aIdx++, books);
}

void deleteAuthorInformation(AUTHOR authors[], char* authorName){
    int idx = findAuthorIndex(authors, authorName);
    if(idx==aIdx){
        printf("[-] Invalid name!\n");
    }else{
        for(int i=idx; i<aIdx-1; i++){
            authors[i] = authors[i+1];
        }
        aIdx--;
    }
}

void updateAuthorInformation(AUTHOR authors[], char* authorName, BOOK books[]){
    int idx = findAuthorIndex(authors, authorName);
    if(idx==aIdx){
        printf("[-] Invalid name!\n");
    }else{
        enterAuthorInformation(authors, idx, books);
    }
}

void printBookInformationByAuthor(AUTHOR * author, int i){
    printf("[-] Book%d ID : %d\n", i, author->writtenBooks[i].bookId);
    printf("[-] Book%d name : ", i);
    puts(author->writtenBooks[i].bookName);
    printf("[-] Book%d publication date : ", i);
    puts(author->writtenBooks[i].publicationDate);
    printf("[-] Book%d publisher name : ", i);
    puts(author->writtenBooks[i].publisherName);
}

void printAuthorInformation(AUTHOR authors[], int idx){
    printf("----------------------------------------\n");
    printf("[-] Author name : ");
    puts(authors[idx].authorName);
    printf("[-] Author address : ");
    puts(authors[idx].authorAddress);
    printf("[-] Author phone number : ");
    puts(authors[idx].authorPhone);
    printf("[-] Author eamil address : ");
    puts(authors[idx].authorEmail);
    printf("[-] Author biography : ");
    puts(authors[idx].authorBiography);
    for(int i=0; i<authors[idx].writtenBookNumber; i++){
        printBookInformationByAuthor(&authors[idx], i);
    }
    printf("----------------------------------------\n");
}

void searchAuthorInformation(AUTHOR authors[], char* authorName){
    int idx = findAuthorIndex(authors, authorName);
    if(idx==aIdx){
        printf("[-] Invalid author name!");
    }else{
        printAuthorInformation(authors, idx);
    }
}
