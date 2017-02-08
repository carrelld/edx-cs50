#include <stdio.h>
#include <string.h>

void tokenize(char* line)
{
   char* cmd = strtok(line," ");

   while (cmd != NULL)
   {
        printf ("%s\n",cmd);
        cmd = strtok(NULL, " ");
   } 
}

int main(void)
{
   char* line = "this is a test";
   tokenize(line);
}