#include<stdio.h>
#include<string.h>

int idx = 0;

typedef struct _Book {
    int id;
    char name[30];
    char publicationDate[11];
    char publisherName[30];
    char publishserPhoneNumber[14];
    char authorName[30];
    char authorEmailAddress[30];
} Book;

void printGuide(void);

int isPositive(int n);
int isCheck(int id, Book books[]);
int isFull(void);
int isEmpty(void);
int isEffective(int id, Book books[]);

void enterBookInformation(Book books[]);
int enterId(void);
int enterMenu(void);

int findBookIndex(int id, Book books[]);

void updateBookInformation(int bookIndex, Book books[]);
void deleteBookInformation(int bookIndex, Book books[]);

void printBookInformation(int i, Book books[]);
int searchBookInformation(int id, Book books[]);
int searchBookInformationByAuthor(char author[], Book books[]);
int searchBookInformationByPublisher(char publisher[], Book books[]);
void displayBookInformation(Book books[]);


int main() {
    int menu = 1;
    Book books[100] = {0};
    
    printGuide();
    
    while(menu) {
        menu = enterMenu();
        
        switch(menu) {
            case 0:
                printf("[-] Bye Bye!\n");
                break;

            case 1:{
                if(!isFull()) {
                    int id = 0;
                    
                    do {
                        id = enterId();
                    } while(!isEffective(id, books));
                    
                    books[idx].id = id;
                    enterBookInformation(books);
                }
                break;
            }

            case 2:{
                int id = enterId();
                int bookIndex = 0;

                if(!isEmpty()){
                    bookIndex = findBookIndex(id, books);
                }

                if(bookIndex<=100) {
                    updateBookInformation(bookIndex, books);
                    enterBookInformation(books);
                } else {
                    printf("[-] There is no %d.\n", id);
                }
                break;
            }

            case 3:{
                if(!isEmpty()) {
                    int id = enterId();
                    int bookIndex = findBookIndex(id, books);
                    
                    deleteBookInformation(bookIndex, books);
                    
                    printf("[-] Success\n");
                    idx--;
                }
                break;
            }

            case 4:{
                if(!isEmpty()) {
                    int id = enterId();
                    
                    if(!searchBookInformation(id, books)){
                        printf("[-] There is no %d\n", id);
                    }
                }
                break;
            }

            case 5:{
                if(!isEmpty()) {
                    char bookAuthor[30] = {0};
                    printf("[+] Enter book\'s author : ");
                    scanf("%s", bookAuthor);
                    
                    if(!searchBookInformationByAuthor(bookAuthor, books)){
                        printf("[-] Ther is no ");
                        puts(bookAuthor);
                    }
                }
                
                break;
            }

            case 6:{
                if(!isEmpty()) {
                    char bookPublisher[30] = {0};
                    printf("[+] Enter book\'s publisher : ");
                    scanf("%s", bookPublisher);
                    if(!searchBookInformationByPublisher(bookPublisher, books)){
                        printf("[-] There is no ");
                        puts(bookPublisher);
                    }
                }
                break;
            }

            case 7:{
                if(!isEmpty()){
                    displayBookInformation(books);
                }
                break;
            }

            default:
                printf("[!] Unvalid menu. Try again\n");
                break;
        }
    }
}

int isPositive(int n) {
    if(n >= 0) {
        return 1;
    } else {
        return 0;
    }
}

int isCheck(int id, Book books[]) {
    int i=0;
    
    for(;i<idx; i++) {
        if(id==books[i].id){
            return 1;
        }
    }
    
    return 0;
}

int isFull() {
    if(idx >= 100) {
        printf("[-] It\'s full");
        return 1;
    }
    return 0;
}

void enterBookInformation(Book books[]) {
    printf("[+] Enter book\'s name : ");
    fflush(stdin);
    gets(books[idx].name);

    printf("[+] Enter book\'s publication date : ");
    fflush(stdin);
    gets(books[idx].publicationDate);

    printf("[+] Enter publisher\'s name : ");
    fflush(stdin);
    gets(books[idx].publisherName);

    printf("[+] Enter publisher\'s phone number : ");
    fflush(stdin);
    gets(books[idx].publishserPhoneNumber);

    printf("[+] Enter author\'s name : ");
    fflush(stdin);
    gets(books[idx].authorName);

    printf("[+] Enter author\'s email address : ");
    fflush(stdin);
    gets(books[idx++].authorEmailAddress);

    printf("[-] Success!\n");
}

int isEffective(int id, Book books[]) {
    if(isPositive(id)) {
        if(idx==0) {
            books[idx].id = id;
            return 1;
        } else {
            if(isCheck(id, books)){
                printf("[!] Book\'s id should be unique. Try again.\n");
                return 0;
            } else {
                return 1;
            }
        }
    } else {
        printf("[!] Book\'s id should not be negative number. Try again.\n");
        return 0;
    }
}

int enterId() {
    int id = 0;
    
    printf("[+] Enter book\'s id : ");
    scanf("%d", &id);
    
    return id;
}

void printGuide(){
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
}

int enterMenu() {
    int menu = 0;
    printf("\n[+] Select menu : ");
    scanf("%d", &menu);
    return menu;
}

int isEmpty() {
    if(idx==0) {
        printf("[-] Empty\n");
        return 1;
    } else {
        return 0;
    }
}

int findBookIndex(int id, Book books[]) {
    for(int i=0; i<idx; i++) {
        if(books[i].id == id) {
            return i;
        }
    }
    return 101;
}

void updateBookInformation(int bookIndex, Book books[]) {
    while(1) {
        int id = enterId();
        if(isEffective(id, books)) {
            books[bookIndex].id = id;
            break;
        }
    }
}

void deleteBookInformation(int bookIndex, Book books[]) {
    for(int i=bookIndex; i<idx-1; i++){
        books[i] = books[i+1];
    }
}

void printBookInformation(int i, Book books[]) {
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

int searchBookInformation(int id, Book books[]) {
    for(int i=0; i<idx; i++) {
        if(books[i].id == id) {
            printBookInformation(i, books);
            return 1;
        }
    }
    return 0;
}

int searchBookInformationByAuthor(char author[], Book books[]) {
    for(int i=0; i<idx; i++) {
        if(!strcmp(books[i].authorName, author)) {
            printBookInformation(i, books);
            return 1;
        }
    }
    return 0;
}

int searchBookInformationByPublisher(char publisher[], Book books[]) {
    for(int i=0; i<idx; i++) {
        if(!strcmp(books[i].publisherName, publisher)){
            printBookInformation(i, books);
            return 1;
        }
    }
    return 0;
}

void displayBookInformation(Book books[]) {
    for(int i=0; i<idx; i++) {
        printBookInformation(i, books);
    }
}
