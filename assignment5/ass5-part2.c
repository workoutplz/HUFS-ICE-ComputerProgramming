//ass5 part2

#include<stdio.h>

int main() {
    int size, cnt, number, flag, tmp, full = 0;
    int task = 1;
    printf("[+] Enter limit of student number. : ");
    scanf("%d", &size);
    
    int studentId[size];
    for(int i=0; i<size; i++) {
        studentId[i] = 0;
    }
    
    while(task) {
        if(cnt >= size) {
            cnt = size;
            full = 1;
        } else {
            full = 0;
        }
        printf("\n\n[i] 1. Add student ID.\n");
        printf("[i] 2. Delete stduent ID.\n");
        printf("[i] 3. Insert student ID at a given position or index.\n");
        printf("[i] 4. Search student ID.\n");
        printf("[i] 5. Update student ID.\n");
        printf("[i] 6. Display student ID.\n");
        printf("[i] 0. Exit this program.\n");
        printf("[i] Student ID can\'t be \'0\'\n\n");
        printf("[+] Enter a task number. : ");
        scanf("%d", &task);
        
        switch(task) {
            case 1:
                if (full) {
                    printf("[!] Unable to add student ID. It\'s full.\n");
                } else {
                    printf("[+] Enter a student ID : ");
                    scanf("%d", &number);
                    for(int i=0; i<size; i++) {
                        if(studentId[i] == number) {
                            printf("[!] %d is already in %d\n", number, i);
                            flag = 0;
                            break;
                        } else {
                            flag = 1;
                        }
                    }
                    if(flag) {
                        studentId[cnt++] = number;
                        printf("[-] Success to add %d in %d\n", number, cnt-1);
                    }
                }
                break;
            
            case 2:
                printf("[+] Enter a index number : ");
                scanf("%d", &number);
                if(number <= size) {
                    tmp = number;
                    for(; number<size; number++){
                        studentId[number] = studentId[number+1];
                    }
                    studentId[size-1] = 0;
                    cnt--;
                    printf("[-] Deleted.\n");
                } else {
                    printf("[!] Invalid value.\n");
                }
                break;
            
            case 3: {
                if (full) {
                    printf("[!] Unable to insert student ID. It\'s full.\n");
                } else {
                    int sizeTmp = size;
                    printf("[+] Enter a index number : ");
                    scanf("%d", &number);
                    tmp = number;
                    printf("[+] Enter a student ID : ");
                    scanf("%d", &number);
                    for(int i=0; i<size; i++) {
                        if(number == studentId[i]) {
                            printf("[!] %d is already in %d\n", number, i);
                            flag = 0;
                            break;
                        } else {
                            flag = 1;
                        }
                    }
                    if(flag) {
                        for(; sizeTmp>tmp; sizeTmp--) {
                            studentId[sizeTmp] = studentId[sizeTmp-1];
                        }
                        studentId[tmp] = number;
                        cnt++;
                        printf("[-] %d is in %d.\n", number, tmp);
                    }
                }
                break;
            }
            
            case 4:
                printf("[+] Enter student ID : ");
                scanf("%d", &number);
                for(int i=0; i<size; i++) {
                    if(studentId[i] == number) {
                        printf("[-] %d in %d\n", number, i);
                        flag = 0;
                        break;
                    } else {
                        flag = 1;
                    }
                }
                if(flag) {
                    printf("[-] There is no %d.\n", number);
                }
                break;
                
            case 5:
                printf("[+] Enter a index number : ");
                scanf("%d", &number);
                tmp = studentId[number];
                
                printf("[+] Enter a new student ID : ");
                scanf("%d", &studentId[number]);
                
                for(int i=0; i<size; i++) {
                    if(studentId[i] == tmp) {
                        printf("[-] %d in %d\n", number, i);
                        flag = 0;
                        break;
                    } else {
                        flag = 1;
                    }
                }
                if(flag) {
                    printf("[-] There is no %d.\n", number);
                }
                
                printf("[-] %d is change to %d.\n", tmp, studentId[number]);
                break;
                
            case 6:
                for(int i=0; i<size; i++) {
                    printf("[-] %d\'s ID : %d\n", i, studentId[i]);
                }
                break;
            
            case 0:
                break;
            
            default:
                printf("[!] Error! Invalid task number.\n");
                break;
        }
    }
    
    printf("[i] Exit the program.\n");
    return 0;
}
