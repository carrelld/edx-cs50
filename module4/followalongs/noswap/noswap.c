/**
* Filename: noswap.c
* Save in Folder: ~/workspace/module4/followalongs/noswap
* 
* Include the stdio library
*
* Declare a function called swap with a return-type of void and an argument list consisting of two variables called a and b of type int.
* Hint: return-type name(argument-list)
*
* Add main method
*
*    Declare a variable called x and assign the value 1 to it
*    Declare a variable called y and assign the value 2 to it
* 
*    Print "x is %i\n" using x as the value for the placeholder %i
*    Print "y is %i\n" using y as the value for the placeholder %i
*    Print "Swapping...\n" 
*    Call the swap function
*    Print "Swapped!\n" 
*    Print "x is %i\n" using x as the value for the placeholder %i
*    Print "y is %i\n" using y as the value for the placeholder %i
* 
* You will find instructions to complete this task in the video. 
* You will be modifying this code as you go along.
*
*/

#include <stdio.h>

void swap(int a, int b);

int main(void)
{
    int x = 1;
    int y = 2;
    
    printf("x is %i\n", x);
    printf("y is %i\n", y);
    printf("Swapping...\n");
    swap(x, y);
    printf("x is %i\n", x);
    printf("y is %i\n", y);
    printf("Swapping...\n");
}

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}