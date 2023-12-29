#include <stdio.h>
#include <time.h>

int moon_phase(int year,int month,int day);

int main(int argc, char *argv[]) {
    char *phase[8] = {
            "waxing crescent", "at first quarter",
            "waxing gibbous", "full", "waning gibbous",
            "at last quarter", "waning crescent", "new"
    };
    time_t now;
    struct tm *clock;
    int m_phase;
    char time_string[64];

    time(&now);
    clock = localtime(&now);

    strftime(time_string, 64, "Today is %A, %B, %d, %Y\nIt is %r%n", clock);

    m_phase = moon_phase(clock->tm_year+1900, clock->tm_mon, clock->tm_mday);
    if (argc > 1) {
        printf("Greetings %s!", argv[1]);
    }
    printf("\n%s", time_string);
    printf("Current moon phase is %s\n", phase[m_phase]);
    return (0);
}

// 8 phases of moon copied from internet
int moon_phase(int year,int month,int day)
{
    int d,g,e;
 
    d = day;
    if(month == 2)
        d += 31;
    else if(month > 2)
        d += 59+(month-3)*30.6+0.5;
    g = (year-1900)%19;
    e = (11*g + 29) % 30;
    if(e == 25 || e == 24)
        ++e;
    return ((((e + d)*6+5)%177)/22 & 7);
}

