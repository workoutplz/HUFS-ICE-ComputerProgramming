#include<stdio.h>
#include<string.h>

struct Book {
    int id;
    char name[30];
    char publicationDate[11];
    char publisherName[30];
    char publishserPhoneNumber[14];
    char authorName[30];
    char authorEmailAddress[30];
};

int isPositive(int n) {
    if(n >= 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int index = 0;
    int menu = 1;
    struct Book books[100] = {0};
    
    printf("[i] This is library program.\n");
    printf("[i] Menu 1. Add book information.\n");
    printf("[i] Menu 2. Update book information by. ook\'s id..\n");
    printf("[i] Menu 3. Delete book information by book\'s id.\n");
    printf("[i] Menu 4. Search book information by book\'s id.\n");
    printf("[i] Menu 5. Display a list of book(s) published by an author\'s name.\n");
    printf("[i] Menu 6. Display a list of book(s) published by a publisher\'s name.\n");
    printf("[i] Menu 7. Display a list of all book.\n");
    printf("[i] Menu 0. Exit\n");
    printf("[i] Book\'s id should be unique and can not be a negative number.\n");
    
    while(menu) {
        printf("\n[+] Select menu : ");
        scanf("%d", &menu);

        switch (menu) {
            case 0:
                printf("[-] Bye Bye!\n");
                break;
            
            case 1:{
                if(index >= 100) {
                    printf("[-] It\'s full");
                } else {
                    int id = 0;
                    int i = 0;

                    while(1){
                        printf("[+] Enter book\'s id : ");
                        scanf("%d", &id);
                        if(isPositive(id)) {
                            if(index==0) {
                                books[index].id = id;
                                break;
                            } else {
                                for(i=0; i<index; i++) {
                                    if(books[i].id == id) {
                                        printf("[!] Book\'s id should be unique. Try again.\n");
                                        break;
                                    }
                                }
                                if(i==index) {
                                    books[index].id = id;
                                    break;
                                }
                            }
                        } else {
                            printf("[!] Book\'s id should not be negative number. Try again.\n");
                        }
                    }

                    printf("[+] Enter book\'s name : ");
                    fflush(stdin);
                    gets(books[index].name);

                    printf("[+] Enter book\'s publication date : ");
                    fflush(stdin);
                    gets(books[index].publicationDate);

                    printf("[+] Enter publisher\'s name : ");
                    fflush(stdin);
                    gets(books[index].publisherName);

                    printf("[+] Enter publisher\'s phone number : ");
                    fflush(stdin);
                    gets(books[index].publishserPhoneNumber);

                    printf("[+] Enter author\'s name : ");
                    fflush(stdin);
                    gets(books[index].authorName);

                    printf("[+] Enter author\'s email address : ");
                    fflush(stdin);
                    gets(books[index++].authorEmailAddress);
                    
                    printf("[-] Success!\n");
                }
                break;
            }
            
            case 2:{
                int id = 0;
                int isCheck = 0;
                int bookIndex = 0;
                printf("[+] Enter book\'s id : ");
                scanf("%d", &id);

                if (index==0) {
                    printf("[-] Empty\n");
                } else {
                    for(int i=0; i<index; i++) {
                        if(books[i].id == id) {
                            bookIndex = i;
                            isCheck = 1;
                            break;
                        }
                    }
                }

                if (isCheck) {
                    int id = 0;
                    int i = 0;

                    while(1){
                        printf("[+] Enter book\'s new id : ");
                        scanf("%d", &id);
                        if(isPositive(id)) {
                            if(index==0) {
                                books[index].id = id;
                                break;
                            } else {
                                for(i=0; i<index; i++) {
                                    if(books[i].id == id) {
                                        printf("[!] Book\'s id should be unique. Try again.\n");
                                        break;
                                    }
                                }
                                if(i==index) {
                                    books[bookIndex].id = id;
                                    break;
                                }
                            }
                        } else {
                            printf("[!] Book\'s id should not be negative number. Try again.\n");
                        }
                    }

                    printf("[+] Enter book\'s new name : ");
                    fflush(stdin);
                    gets(books[bookIndex].name);

                    printf("[+] Enter book\'s new publication date : ");
                    fflush(stdin);
                    gets(books[bookIndex].publicationDate);

                    printf("[+] Enter publisher\'s new name : ");
                    fflush(stdin);
                    gets(books[bookIndex].publisherName);

                    printf("[+] Enter publisher\'s new phone number : ");
                    fflush(stdin);
                    gets(books[bookIndex].publishserPhoneNumber);

                    printf("[+] Enter author\'s new name : ");
                    fflush(stdin);
                    gets(books[bookIndex].authorName);

                    printf("[+] Enter author\'s new email address : ");
                    fflush(stdin);
                    gets(books[bookIndex].authorEmailAddress);
                    
                    printf("[-] Success!\n");
                } else {
                    printf("[-] There is no %d.\n", id);
                }
                break;
            }
            
            case 3:{
                int id = 0;
                int bookIndex = 0;
                if (index==0) {
                    printf("[-] Empty\n");
                }
                else {
                    printf("[+] Enter book\'s id : ");
                    scanf("%d", &id);
                    for(int i=0; i<index; i++) {
                        if(books[i].id == id) {
                            bookIndex = i;
                            break;
                        }
                    }
                    for(int i=bookIndex; i<index-1; i++){
                        books[i].id = books[i+1].id;
                        strcpy(books[i].name, books[i+1].name);
                        strcpy(books[i].authorEmailAddress, books[i+1].authorEmailAddress);
                        strcpy(books[i].authorName, books[i+1].authorName);
                        strcpy(books[i].publicationDate, books[i+1].publicationDate);
                        strcpy(books[i].publisherName, books[i+1].publisherName);
                        strcpy(books[i].publishserPhoneNumber, books[i+1].publishserPhoneNumber);
                        //books[i] = bokks[i+1]; 로 수정해야함.
                    }
                    printf("[-] Success\n");
                    index--;
                }
                break;
            }
            
            case 4:{
                int isCheck= 0;
                int id = 0;
                if (index == 0) {
                    printf("[-] Empty\n");
                } else {
                    printf("[+] Enter book\'s id : ");
                    scanf("%d", &id);
                    for(int i=0; i<index; i++) {
                        if(books[i].id == id) {
                            printf("----------------------------------------\n");
                            printf("[-] Book ID : %d\n", books[i].id);
                            printf("[-] Book name : ");
                            puts(books[i].name);
                            printf("[-] Book publication date : ");
                            puts(books[i].publicationDate);
                            printf("[-] Book publisher name : ");
                            puts(books[i].publisherName);
                            printf("[-] Book publihser phone number : ");
                            puts(books[i].publishserPhoneNumber);
                            printf("[-] Book author name : ");
                            puts(books[i].authorName);
                            printf("[-] Book author email address : ");
                            puts(books[i].authorEmailAddress);
                            printf("----------------------------------------\n");
                            isCheck = 1;
                            break;
                        }
                    }
                }

                if(!isCheck) {
                    printf("[-] There is no %d\n", id);
                }
                break;
            }
            
            case 5:{
                int isCheck = 0;
                char bookAuthor[30] = {0};
                if (index == 0) {
                    printf("[-] Empty\n");
                } else {
                    printf("[+] Enter book\'s author : ");
                    scanf("%s", bookAuthor);
                    for(int i=0; i<index; i++) {
                        if(!strcmp(books[i].authorName, bookAuthor)) {
                            printf("----------------------------------------\n");
                            printf("[-] Book ID : %d\n", books[i].id);
                            printf("[-] Book name : ");
                            puts(books[i].name);
                            printf("[-] Book publication date : ");
                            puts(books[i].publicationDate);
                            printf("[-] Book publisher name : ");
                            puts(books[i].publisherName);
                            printf("[-] Book publihser phone number : ");
                            puts(books[i].publishserPhoneNumber);
                            printf("[-] Book author name : ");
                            puts(books[i].authorName);
                            printf("[-] Book author email address : ");
                            puts(books[i].authorEmailAddress);
                            printf("----------------------------------------\n");
                            isCheck = 1;
                        }
                    }
                }

                if(!isCheck) {
                    printf("[-] There is no ");
                    puts(bookAuthor);
                }
                break;
            }

            case 6:{
                int isCheck = 0;
                char bookPublihser[30] = {0};

                if (index == 0) {
                    printf("[-] Empty\n");
                } else {
                    printf("[+] Enter book\'s publisher : ");
                    scanf("%s", bookPublihser);
                    for(int i=0; i<index; i++) {
                        if(!strcmp(books[i].publisherName, bookPublihser)){
                            printf("----------------------------------------\n");
                            printf("[-] Book ID : %d\n", books[i].id);
                            printf("[-] Book name : ");
                            puts(books[i].name);
                            printf("[-] Book publication date : ");
                            puts(books[i].publicationDate);
                            printf("[-] Book publisher name : ");
                            puts(books[i].publisherName);
                            printf("[-] Book publihser phone number : ");
                            puts(books[i].publishserPhoneNumber);
                            printf("[-] Book author name : ");
                            puts(books[i].authorName);
                            printf("[-] Book author email address : ");
                            puts(books[i].authorEmailAddress);
                            printf("----------------------------------------\n");
                            isCheck = 1;
                        }
                    }
                }

                if(!isCheck) {
                    printf("[-] There is no ");
                    puts(bookPublihser);
                }
                break;
            }

            case 7:{
                if (index == 0) {
                    printf("[-] Empty\n");
                } else {
                    for(int i=0; i<index; i++) {
                        printf("----------------------------------------\n");
                        printf("[-] Book ID : %d\n", books[i].id);
                        printf("[-] Book name : ");
                        puts(books[i].name);
                        printf("[-] Book publication date : ");
                        puts(books[i].publicationDate);
                        printf("[-] Book publisher name : ");
                        puts(books[i].publisherName);
                        printf("[-] Book publihser phone number : ");
                        puts(books[i].publishserPhoneNumber);
                        printf("[-] Book author name : ");
                        puts(books[i].authorName);
                        printf("[-] Book author email address : ");
                        puts(books[i].authorEmailAddress);
                        printf("----------------------------------------\n");
                    }
                }
                break;
            }
            
            default:
                printf("[!] Unvalid menu. Try again\n");
                break;
        }
    }
}