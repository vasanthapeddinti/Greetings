#include <stdio.h>
#include <time.h>

int main() 
{
    clock_t c_init, c_final;

    // calculate process start time
    c_init = clock();
    time_t now;

    time(&now);
    printf("The epoch time is %ld\n",now);
    printf("%s",ctime(&now));

    // calculate process final time
    c_final = clock();
    printf("Time the process spend is %ld\n", c_final-c_init);
    return(0);
}