//5-8
#include<stdio.h>
#include<math.h>
int main() {
    int t_departure[8] = {480, 583, 679, 767, 840, 945, 1140, 1305};
    int hour, minute, time, index = 0;

    printf("Enter a 24-hour time : ");
    scanf("%d:%d", &hour, &minute);

    time = hour*60 + minute;

    printf("%d\n", time);
    for(int i=0; i<8; i++) {
        t_departure[i] = abs(time - t_departure[i]);
    }

    int closet = t_departure[0];

    for(int i=0; i<8; i++) {
        if(closet > t_departure[i]) {
            closet = t_departure[i];
            index = i;
        }
    }

    switch(index) {
        case 0:
            printf("Closet departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
            break;
        case 1:
            printf("Closet departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
            break;
        case 2:
            printf("Closet departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
            break;
        case 3:
            printf("Closet departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
            break;
        case 4:
            printf("Closet departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
            break;
        case 5:
            printf("Closet departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
            break;
        case 6:
            printf("Closet departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
            break;
        case 7:
            printf("Closet departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
            break;
        default:
            break;
    }
}
