#include <stdio.h>
#include "salparser.h"

char *strArray[5];

int main(int argc, char *argv[])
{
	char **filecontent = NULL;
	filecontent = parser("file.txt");
	return 0;
}

char** parser(char filename[])
{
	/*********************************************************/
	//	                 File Operations                     //
	/*********************************************************/
	
	// File opening
    FILE* fp = open_file(filename);
    if (fp == NULL)
    {
        printf("\nFile could not be opened!!\n");
        getchar();
        exit(1); // quit
    }

    //Reading the file
    int line_count;
    char** file = NULL;
    line_count = countlines(fp);
    file = read_file(fp, line_count);
    
    
    int i;
    for ( i = 0; i < line_count; i++)
    {
        chkmain(i, file[i], line_count);
    }
    
    fclose(fp);

    return file;
}