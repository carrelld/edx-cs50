/**
  * Filename: structs.h
  * Save in Folder: ~/workspace/module4/followalongs/structs
  * 
  * Include the cs50 library
  *
  * define a type for a student
  * Hint: typedef struct
  *    Declare a variable called name of type string
  *    Declare a variable called house of type string
  * Name this datatype student
  * Hint: <datatype>;
  */
#include <cs50.h>

typedef struct
{
    string name;
    string house;
} student;