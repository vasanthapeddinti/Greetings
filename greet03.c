#include<stdio.h>
#include<time.h>

int main(int argc, char *argv[])
{
    time_t now;
    struct tm *clock;
    int hour;

    time(&now);
    clock = localtime(&now);
    hour = clock->tm_hour;

    printf("What a beautiful ");
    if (hour < 12) {
        printf("morning");
    } else if (hour < 17) {
        printf("afternoon");
    } else if (hour < 21) {
        printf("evening");
    } else {
        printf("night");
    }

    if (argc > 1) {
        printf(" %s!",argv[1]);
    }
    printf("\n");

    return (0);
}