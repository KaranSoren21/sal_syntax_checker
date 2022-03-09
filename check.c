#include "salparser.h"

char *strArray[5];
char line_number[SIZE];

int chkspaces(char *str)
{
    int i, space_count = 0;
    char ch;

    for(i = 0; i < strlen(str); i++)
    {
        ch = str[i];
        if(ch == ' ')
        {
            space_count++;
        }
        if (space_count > 2)
        {
            return 1;
        }
    }
    return 0;
}

char* generate_linenumber(int line,int totallines)
{
    int num = line - 1;
    char str[4];
    char zero[] = "0";
    char end[] = ":";
    sprintf(str, "%d", num);
    if (totallines < 10)
    {
        snprintf( line_number, sizeof( line_number ), "%s%s%s", zero, str,end);
    }
    if (totallines > 9 && totallines < 100)
    {
        snprintf( line_number, sizeof( line_number ), "%s%s%s%s", zero,zero,str,end);
    }
    if (totallines > 99 && totallines < 1000)
    {
        snprintf( line_number, sizeof( line_number ), "%s%s%s%s%s", zero,zero,zero,str,end);
    }
    return line_number;
}

int chkcapital(char str[])
{
    int i;
    char c;
    for ( i = 0; i < strlen(str) ;i++)
    {
        char c = str[i];
        if (!isalpha(c) && !isupper(c))
        {
            return 1;
        }
    }
    return 0;
}


//Extract words from a string and store in strArray and check opcode
int chkopcode(char str[])
{
    int i, j;
    char *token = strtok(str, " ");
    char *arithmetic[] = {"ADD","SUB","MULT","DIV"};
    char *branch[] = {"BRANN","BRAN","BRANZ"}; 
    char *io[] = {"READ","WRITE","LOAD","STORE"};

    for( j = 0; j <= 3; j++ )
    {
        strArray[j] = malloc(100*sizeof(char));
    }

    while(token != NULL)
    {
        strcpy(strArray[i], token);
        token = strtok(NULL, " ");
        i++;
    }
    for (i = 0; i < 4; i++)
    {
        if (!strcmp(strArray[1],arithmetic[i]) || !strcmp(strArray[1],branch[i]) || !strcmp(strArray[1],io[i]) || !strcmp(strArray[1],"HALT") )
        {
            return 1;
        }
    }
    return 0;
}


//Check for 2 token to be a letter
int chkalphabetdefined(char str[])
{
    int i = 0, j;
    char *token = strtok(str, " ");
    
    for( j = 0; j <= 3; j++ )
    {
        strArray[j] = malloc(100*sizeof(char));
    }

    while(token != NULL)
    {
        strcpy(strArray[i], token);
        token = strtok(NULL, " ");
        i++;
    }
    
    char letter = strtok(strArray[1],":");
    if (letter < 65 || letter > 90)
     {
         return 1;
     } 
    return 0;
}


int chknumplus(char str[])
{
    int i = 0, j;
    char *token = strtok(str, " ");
    
    for( j = 0; j <= 3; j++ )
    {
        strArray[j] = malloc(100*sizeof(char));
    }

    while(token != NULL)
    {
        strcpy(strArray[i], token);
        token = strtok(NULL, " ");
        i++;
    }
    
    if (strArray[2][0] != '+')
    {
            return 1;
    }
    return 0;
}


void chkmain(int lineno, char* str, int totallines)
{
        if (!chkspaces(str))
        {
            printf("%d : %s\n",lineno,"Invalid character or space detected");
        }
        if (!chkcapital(str))
        {
            printf("%d : %s\n",lineno,"Small letters detected");
        }
        
        char *token = strtok(str, " ");
        char* givenline;
        strcpy(givenline, token);
        if (!strcmp(givenline,generate_linenumber(lineno,totallines)))
        {
            printf("%d : %s\n",lineno,"Invalid line number detected" );
        }
        if (!chkopcode(str))
        {
            printf("%d : %s\n",lineno,"Invalid character");
        }
        if (!chknumplus(str))
        {
            printf("%d : %s\n",lineno,"Invalid character");
        }
        if (!chkalphabetdefined(str))
        {
            printf("%d : %s\n",lineno,"Invalid character");
        }
}
