//
//  fileIOFunc.c
//  finalexam
//
//  Created by wonjunlee on 2020/06/24.
//  Copyright © 2020 wonjun. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include "fileIOFunc.h"

void putBookInformation(BOOK books[], FILE* fp){
    for(int i=0; i<bIdx; i++){
        fprintf(fp, "%d|%s|%s|%s\n", books[i].bookId, books[i].bookName, books[i].publicationDate, books[i].publisherName);
    }
}

void putBookInformationOfAuthor(BOOK book, FILE* fp){
    fprintf(fp, "|%d|%s|%s|%s", book.bookId, book.bookName, book.publicationDate, book.publisherName);
}

void putAuthorInformation(AUTHOR authors[], FILE* fp){
    for(int i=0; i<aIdx; i++){
        fprintf(fp, "%s|%s|%s|%s|%s|%d", authors[i].authorName, authors[i].authorAddress, authors[i].authorPhone, authors[i].authorEmail, authors[i].authorBiography, authors[i].writtenBookNumber);
        for(int j=0; j<authors[i].writtenBookNumber; j++){
            putBookInformationOfAuthor(authors[i].writtenBooks[j], fp);
        }
        fprintf(fp, "\n");
    }
}

void getBookInformationByFile(FILE* fp, BOOK books[]){
    int i = 0;
    char str[100];
    char tmpStr[10];
    char seps[] = "|";
    char* token = NULL;
    while(!feof(fp)){
        fgets(str, 100, fp);
        if (strlen(str) <= 1) continue;
        str[strlen(str) - 1] = '\0';
        
        token = strtok(str, seps);
        strcpy(tmpStr, token);
        books[i].bookId = atoi(tmpStr);
        
        token = strtok(NULL, seps);
        strcpy(books[i].bookName, token);

        token = strtok(NULL, seps);
        strcpy(books[i].publicationDate, token);

        token = strtok(NULL, seps);
        strcpy(books[i++].publisherName, token);
        
        bIdx++;
    }
}

void getAuthorInformationByFile(FILE* fp, AUTHOR authors[]){
    int i=0;
    char str[1500];
    char seps[] = "|";
    char* token = NULL;
    while(!feof(fp)){
        fgets(str, 1500, fp);
        if (strlen(str) <= 1) continue;
        str[strlen(str) - 1] = '\0';
        
        token = strtok(str, seps);
        strcpy(authors[i].authorName, token);
        
        token = strtok(NULL, seps);
        strcpy(authors[i].authorAddress, token);
        
        token = strtok(NULL, seps);
        strcpy(authors[i].authorPhone, token);
        
        token = strtok(NULL, seps);
        strcpy(authors[i].authorEmail, token);
        
        token = strtok(NULL, seps);
        strcpy(authors[i].authorBiography, token);
        
        token = strtok(NULL, seps);
        authors[i].writtenBookNumber = atoi(token);
        
        for(int j=0; j<authors[i].writtenBookNumber; j++){
            token = strtok(NULL, seps);
            authors[i].writtenBooks[j].bookId = atoi(token);
            
            token = strtok(NULL, seps);
            strcpy(authors[i].writtenBooks[j].bookName, token);
            
            token = strtok(NULL, seps);
            strcpy(authors[i].writtenBooks[j].publicationDate, token);
            
            token = strtok(NULL, seps);
            strcpy(authors[i].writtenBooks[j].publisherName, token);
        }
        
        aIdx++;
    }
}
