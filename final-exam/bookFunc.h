//
//  bookFunc.h
//  finalexam
//
//  Created by wonjunlee on 2020/06/23.
//  Copyright © 2020 wonjun. All rights reserved.
//

#ifndef bookFunc_h
#define bookFunc_h

#include "structs.h"
#include "etcFunc.h"

int isIn(BOOK books[], int bookId);
int isPositive(int bookId);
int isEffective(BOOK books[], int bookId);

void enterBookInformation(BOOK books[], int idx);
void addBookInformation(BOOK books[]);
void deleteBookInformation(BOOK books[], int idx);
void updateBookInformation(BOOK books[], int idx);
void printBookInformation(BOOK books[], int idx);
void findBookInformation(BOOK books[], int bookId);
void displayBookInformation(BOOK books[]);
void printBookInformation2(BOOK book, int bookNumber);
void searchBookInformation(BOOK books[], int bookId);

#endif /* bookFunc_h */
