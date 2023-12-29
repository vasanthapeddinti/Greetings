// Learn about realloc
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BSIZE 256

int main()
{
    const char filename[] = "/root/side/Greetings/pithy.txt";
    FILE *fp;
    char buffer[BSIZE];
    char *r, *entry;
    int items, i;
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
            list_base = (char *)realloc(list_base, sizeof(char *)*(items+100));
            if (list_base == NULL) {
                fprintf(stderr,"Unable to reallocate memory");
                exit(1);
            }
        }
        items++;
    }

    // Step 3: Close the file pointer
    fclose(fp);

    for( i = 0; i < items; i++ ) {
        printf("%s",*(list_base + i));
    }
    return (0);
}