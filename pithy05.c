#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BSIZE 256

int main()
{
    const char filename[] = "/root/side/Greetings/pithy.txt";
    FILE *fp;
    char buffer[BSIZE];
    char *r, *entry;
    int items, saying;
    char **list_base;

    items = 0;

    // Step 1: Open the file and get the file pointer
    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open the file: %s\n", filename);
        exit(1);
    }

    list_base = (char **)malloc(sizeof(char *) * 100);
    if (list_base == NULL) {
        fprintf(stderr, "Unable to allocate memory for list_base\n");
        exit(1);
    }

    // Step 2: Read the file through file pointer and store each line 
    // in char array buffer[] until the end of the file
    while( !feof(fp)) {
        r = fgets(buffer, BSIZE, fp);

        if (r == NULL) {
            break; // break the loop
        }

        // allocate memory for the size of buffer string and copy
        // buffer into entry
        entry = (char *)malloc(sizeof(char) * strlen(buffer) + 1);
        if (entry == NULL) {
            fprintf(stderr,"Unable to allocate memory for entry\n");
            exit(1);
        }

        strcpy(entry, buffer);
        *(list_base + items) = entry;
        if (items%100  == 0) {
            list_base = (char **)realloc(list_base, sizeof(char *)*(items+100));
            if (list_base == NULL) {
                fprintf(stderr,"Unable to reallocate memory");
                exit(1);
            }
        }
        items++;
    }

    // Step 3: Close the file pointer
    fclose(fp);

    // Step 4: Pick a random pointer and print the content of string
    srand( (unsigned)time(NULL));
    saying = rand() % (items - 1);
    printf("Here is a lousy joke for you: \n%s", *(list_base+saying));
    return (0);

    /*
    We have used malloc and realloc(used if pithy.txt has more than 100 lines).
    But, we have not called free() to free up the memory that we created in
    the heap. Since the malloc is residing in the main() function, it is freed
    when the program quits. If the allocation was done inside a function, we
    have to release the memory or we can loose the memory chunk and might
    eventually run into memory overflow.
    */
}