#include<cs50.h>
#include<stdio.h>
#include <stdlib.h>

int main (int argc, string argv[])
{

  // validation: make sure they provided a CL argument
  if (argc < 2) 
  {
    printf("Please provide one integer.\n");
    printf("usage: previous n\n");
    return 1;
  }

  int input = atoi(argv[1]);
  printf ("The previous number is %i\n", input - 1);

  return 0;
}