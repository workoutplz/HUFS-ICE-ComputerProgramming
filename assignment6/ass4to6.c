#include <stdio.h>

int flag;

void printGuide() {
    printf("\n\n[i] Select menu and enter natural number\n\n");
    printf("[i] 1. Display a list of even numbers.\n");
    printf("[i] 2. Display a list of odd numbers.\n");
    printf("[i] 3. For a given number \'n\' check if \'n\' is a prime number.\n");
    printf("[i] 4. Display a list of prime numbers between numbers \'n\' and \'m\'.\n");
    printf("[i] 5. Display a factorial of a given number \'n\'\n");
    printf("[i] 6. Find factorial of all numbers between numbers \'n\' and \'m\'\n");
    printf("[i] 7. Generate the Fibonacci sequence up to a number \'n\'\n");
    printf("[i] 8. Find the sum of the series [x - x^3 + x^5 - ...]\n");
    printf("[i] If you want to exit program, enter \'0\' when select the menu.\n\n");
}

int findSumOfSeries(int n) {
    flag = 1;
    int result = 0;

    for(int i=1; i<=n; i+=2) {
        int number = 1;
        for(int j=1; j<=i; j++) {
            number *= n;
        }
        result += number*flag;
        flag *= -1;
    }

    return result;
}

void fibonacci(int n){
    int firstBefore = 0;
    int secondBefore = 1;
    int now = 1;

    printf("[-] Result : ");
    for(int i=0; i<n; i++) {
        printf("%d ", now);
        now = firstBefore + secondBefore;

        firstBefore = secondBefore;
        secondBefore = now;
    }
}

void displayBetweenFactorial(int n, int m) {
    if(n < m) {
        n++;

        for(; n<m; n++) {
            printf("[-] %d factorial : ", n);

            int fac = 1;

            for(int i=1; i<=n; i++) {
                fac *= i;
            }
            printf("%d\n", fac);
        }
    } else if(n==m) {
        printf("[-] Same number.");
    } else {
        m++;

        for(; m<n; m++) {
            printf("[-] %d factorial : ", m);

            int fac = 1;

            for(int i=1; i<=m; i++) {
                fac *= i;
            }
            printf("%d\n", fac);
        }
    }
}

void displayFactorial(int n, int m) {
    for(int i=1; i<=n; i++) {
        m *= i;
    }
    printf("%d\n", m);
}

void displayEvenNumber(int n) {
    for(int i=1; i<=n; i++) {
        if(i%2==0) {
            printf("%d ", i);
        }
    }
}

void displayOddNumber(int n) {
    for(int i=1; i<=n; i++) {
        if(i%2!=0) {
            printf("%d ", i);
        }
    }
}

void checkPrimeNumber(int n) {
    if(n==2) {
        flag = 1;
    } else {
        for(int i=2; i<n; i++) {
            if(n%i == 0) {
                flag = 0;
                break;
            } else {
                flag = 1;
            }
        }
    }

    if(flag) {
        printf("[-] %d is prime number.", n);
    } else {
        printf("[-] %d is not prime number.", n);
    }
}

void displayBetweenNumber(int n, int m) {
    if(n>m) {
        while(n>m) {
            if(m==2) {
                flag = 1;
            } else {
                for(int i=2; i<m; i++) {
                    if(m%i == 0) {
                        flag = 0;
                        break;
                    } else {
                        flag = 1;
                    }
                }
            }
            if (flag) {
                printf("%d ", m);
            }
            m++;
        }
    } else if (n==m) {
        for(int i=2; i<n; i++) {
            if(n%i == 0) {
                flag = 0;
                break;
            } else {
                flag = 1;
            }
        }
        if(flag) {
            printf("%d ", m);
        }
    } else {
        while(m>n) {
            if(n==2) {
                flag = 1;
            } else {
                for (int i=2; i<n; i++) {
                    if(n%i==0) {
                        flag =0;
                        break;
                    } else {
                        flag =1;
                    }
                }
            }
            if(flag) {
                printf("%d ", n);
            }
            n++;
        }
    }
}

int main() {
    int menu, n, m;
    int program = 1;


    while(program) {
        printGuide();

        printf("[+] Select menu : ");
        scanf("%d", &menu);

        switch(menu) {
            case 0:
                printf("[!] Bye!");
                program = 0;
                break;

            case 1:
                printf("[+] Enter a number : ");
                scanf("%d", &n);

                printf("[-] Result : ");
                displayEvenNumber(n);
                break;

            case 2:
                printf("[+] Enter a number : ");
                scanf("%d", &n);

                printf("[-] Result : ");
                displayOddNumber(n);
                break;

            case 3:
                printf("[+] Enter a number : ");
                scanf("%d", &n);

                checkPrimeNumber(n);
                break;

            case 4:
                printf("[+] Enter two numbers : ");
                scanf("%d %d", &n, &m);

                printf("[-] Result : ");
                displayBetweenNumber(n, m);
                break;

            case 5:
                printf("[+] Enter a number : ");
                scanf("%d", &n);
                m = 1;

                printf("[-] Result : ");
                displayFactorial(n, m);
                break;

            case 6:
                printf("[+] Enter two numbers : ");
                scanf("%d %d", &n, &m);

                displayBetweenNumber(n, m);
                break;

            case 7:
                printf("[+] Enter a number : ");
                scanf("%d", &n);

                fibonacci(n);
                break;

            case 8:
                printf("[+] Enter a number : ");
                scanf("%d", &n);

                int result = findSumOfSeries(n);
                printf("[-] Result : %d", result);
                break;

            default:
                printf("[!] Error! Invalid menu!\n");
                break;
        }
    }
    return 0;
}