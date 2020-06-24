//
//  struct.h
//  finalexam
//
//  Created by wonjunlee on 2020/06/23.
//  Copyright © 2020 wonjun. All rights reserved.
//

#ifndef struct_h
#define struct_h

typedef struct _Book {
    int bookId;
    char bookName[30];
    char publicationDate[30];
    char publisherName[30];
} BOOK;

typedef struct _Author {
    char authorName[30];
    char authorAddress[30];
    char authorPhone[30];
    char authorEmail[30];
    char authorBiography[300];
    int writtenBookNumber;
    BOOK writtenBooks[10];
} AUTHOR;

extern int bIdx;
extern int aIdx;

#endif /* struct_h */
