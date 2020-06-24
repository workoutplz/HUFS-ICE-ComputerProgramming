//
//  fileIOFunc.h
//  finalexam
//
//  Created by wonjunlee on 2020/06/24.
//  Copyright © 2020 wonjun. All rights reserved.
//

#ifndef fileIOFunc_h
#define fileIOFunc_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structs.h"

void putBookInformation(BOOK books[], FILE* fp);
void putBookInformationOfAuthor(BOOK book, FILE* fp);
void putAuthorInformation(AUTHOR authors[], FILE* fp);

void getBookInformationByFile(FILE* fp, BOOK books[]);
void getAuthorInformationByFile(FILE* fp, AUTHOR authors[]);

#endif /* fileIOFunc_h */
