#include <stdio.h>
#include "salparser.h"

// Open the file
FILE *open_file(char filename[])
{
    FILE *fileptr = NULL;
    fileptr = fopen(filename, "r");
    if (fileptr) {
        return fileptr;
    }
    return NULL; // error
}


// Read the file and store in a string array
char** read_file(FILE* txt, int line_count) 
{
    char **array = NULL;     /* Array of lines */
    int i;                   /* Loop counter */
    char line[100];          /* Buffer to read each line */
    int line_length;         /* Length of a single line */
    rewind(txt);
    array = malloc(line_count * sizeof(char *));
    if (array == NULL) 
    {
        return NULL; /* Error */
    }
    for (i = 0; i < line_count; i++) 
    {    
        fgets(line, sizeof(line), txt);
        line_length = strlen(line);        
        line[line_length - 1] = '\0';
        line_length--; /* update line length */
        array[i] = malloc(line_length + 1);
        strcpy(array[i], line);
    }
    return array;
}


// Count the number of lines in file
int countlines(FILE *fp)
{
    int ch=0;
    int lines = 0;
    if (fp == NULL)
        return 0;
    lines++;
    while(!feof(fp))
    {
        ch = fgetc(fp);
        if(ch == '\n')
        {
            lines++;
        }
    }
    return lines;
}

