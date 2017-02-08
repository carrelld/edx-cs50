/**
  * Filename: argv-0.c
  * Save in Folder: ~/workspace/module2/followalongs/argv
  * 
  * Include the stdio library
  * Include the cs50 library
  * Add main method that has two arguments: argc of type int, argv an array of strings
  *    Print "%s\n" using the 1st element of the array argv as the value of the placeholder "%s"
  * 
  * You will find instructions to complete this task in the video. 
  * You will be modifying this code as you go along.
  *
  */
  
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    printf("%s\n", argv[1]);
}