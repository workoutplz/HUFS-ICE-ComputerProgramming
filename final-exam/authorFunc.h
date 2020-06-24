//
//  authorFunc.h
//  finalexam
//
//  Created by wonjunlee on 2020/06/23.
//  Copyright © 2020 wonjun. All rights reserved.
//
#ifndef authorFunc_h
#define authorFunc_h

#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "bookFunc.h"

void getBook(AUTHOR *author, BOOK books[], int wBookId, int i);

int findAuthorIndex(AUTHOR authors[], char* authorName);
void enterAuthorInformation(AUTHOR authors[], int idx, BOOK books[]);
void addAuthorInformation(AUTHOR authors[], BOOK books[]);
void deleteAuthorInformation(AUTHOR authors[], char* authorName);
void updateAuthorInformation(AUTHOR authors[], char* authorName, BOOK books[]);
void printAuthorInformation(AUTHOR authors[], int idx);
void searchAuthorInformation(AUTHOR authors[], char* authorName);

#endif /* authorFunc_h */
