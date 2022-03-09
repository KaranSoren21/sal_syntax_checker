#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 10

// In file SALParser.c
char** parser(char filename[]);
char** tokenline(char str[]);

// In file fileoperation.c
FILE *open_file(char filename[]);
char** read_file(FILE* txt, int line_count);
int countlines(FILE *fp);

// In file check.c
int checkspaces(char *str);
char* generate_linenumber(int line,int totallines);
int checkcapital(char str[]);
int chkalphabetdefined(char str[]);

//1 --> incorrect
//0 --> correct