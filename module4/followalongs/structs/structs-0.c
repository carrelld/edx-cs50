/**
  * Filename: structs-0.c
  * Save in Folder: ~/workspace/module4/followalongs/structs
  * 
  * Include the stdio library
  * Include the cs50 library
  * Include the string library
  *
  * Include the "structs.h" library 
  * Remember: To include a header file from the current directory the library name must be enclosed in double quotes.
  *
  * Define a constant named STUDENTS with a value of 3
  * Hint: #define <NAME> value
  *
  * Add main method
  *   Declare an array called students of type student and specify the size as 3 using the constant STUDENTS. 
  *   (Remember: STUDENTS value is 3)
  *   Hint: <type> <arrayname>[<SIZE>];
  *
  *   For( i=0; i < STUDENTS; i++ )
  *       print "Student's name: "
  *       
  * 
  * You will find instructions to complete this task in the video. 
  * You will be modifying this code as you go along.
  *
  */

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include "structs.h"

#define STUDENTS 3

int main(void)
{
    student students[STUDENTS];
    
    for (int i = 0; i < STUDENTS; i++)
    {
        printf("Student's name: ");
        students[i].name = GetString();
        
        printf("Student's house: ");
        students[i].house = GetString();
    }
    
    for (int i = 0; i < STUDENTS; i++)
    {
        printf("%s is in %s. \n", students[i].name, students[i].house);
    }
    
    for (int i = 0; i < STUDENTS; i ++)
    {
        free(students[i].name);
        free(students[i].house);
    }
}



