  /**
   * Filename: rectangle.c
   * Save in Folder: ~/workspace/module1/studios/rectangle
   * 
   * Write a program that "draws" a rectangle made of hearts "<3" on the console.
   * Your program should prompt the user for a width and a height, and then
   * print the corresponding rectangle.
   * 
   * Example:
   *    $ ./rectangle
   *    Width: 8
   *    Height: 3
   *    <3<3<3<3<3<3<3<3
   *    <3<3<3<3<3<3<3<3
   *    <3<3<3<3<3<3<3<3
   * 
   */
   
#include <stdio.h>
#include <cs50.h>

int main()
{
    printf("Height: ");
    int h = GetInt();
    printf("Width: ");
    int w = GetInt();
    
    for(int row = 0; row < h; row++)
    {
        for(int col = 0; col < w; col++)
        {
            printf("<3");
        }
        printf("\n");
    }
}