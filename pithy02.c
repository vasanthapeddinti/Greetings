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
    int items = 0;

    // Step 1: Open the file and get the file pointer
    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open the file: %s\n", filename);
        exit(1);
    }

    // Step 2: Read the file through file pointer and store each line 
    // in char array buffer[] until the end of the file
    while( !feof(fp)) {
        r = fgets(buffer, BSIZE, fp);

        if (r == NULL) {
            printf("file is empty\n");
            break;
        }

        // allocate memory for the size of buffer string and copy
        // buffer into entry
        entry = (char *)malloc(sizeof(char) * strlen(buffer) + 1);
        if (entry == NULL) {
            fprintf(stderr,"Unable to allocate memory\n");
            exit(1);
        }

        strcpy(entry, buffer);
        printf("%d : %s", items, buffer); // modify this to randomly select a single string and print
        items++;
    }

    // Step 3: Close the file pointer
    fclose(fp);

    return (0);
}