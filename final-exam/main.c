//
//  main.c
//  finalexam
//
//  Created by wonjunlee on 2020/06/23.
//  Copyright © 2020 wonjun. All rights reserved.
//

#include <stdio.h>
#include "authorFunc.h"
#include "fileIOFunc.h"

int main() {
    int menu, bookId = 0;
    char authorName[30] = {};
    BOOK books[100] = {};
    AUTHOR authors[100] = {};
    
    FILE *bookFile, *authorFile;
    
    printGuide1();
    getMenu(&menu);
    switch (menu) {
        case 1:
            bookFile = fopen("/Users/wonjunlee/Desktop/bookInformation.txt", "r+");
            authorFile = fopen("/Users/wonjunlee/Desktop/authorInformation.txt", "r+");
            getBookInformationByFile(bookFile, books);
            getAuthorInformationByFile(authorFile, authors);
            fclose(bookFile);
            fclose(authorFile);
        default:
            bookFile = fopen("/Users/wonjunlee/Desktop/bookInformation.txt", "w");
            authorFile = fopen("/Users/wonjunlee/Desktop/authorInformation.txt", "w");
            break;
    }
    
    do {
        printGuide2();
        getMenu(&menu);
        switch (menu) {
            case 1:
                addBookInformation(books);
                break;
            case 2:
                getBookId(&bookId);
                updateBookInformation(books, bookId);
                break;
            case 3:
                getBookId(&bookId);
                deleteBookInformation(books, bookId);
                break;
            case 4:
                getBookId(&bookId);
                searchBookInformation(books, bookId);
                break;
            case 5:
                displayBookInformation(books);
                break;
            case 6:
                addAuthorInformation(authors, books);
                break;
            case 7:
                getAuthorName(authorName);
                updateAuthorInformation(authors, authorName, books);
                break;
            case 8:
                getAuthorName(authorName);
                deleteAuthorInformation(authors, authorName);
                break;
            case 9:
                getAuthorName(authorName);
                searchAuthorInformation(authors, authorName);
                break;
            default:
                break;
        }
    }while(menu);
    
    putBookInformation(books, bookFile);
    putAuthorInformation(authors, authorFile);
    
    fclose(bookFile);
    fclose(authorFile);
    
    return 0;
}
