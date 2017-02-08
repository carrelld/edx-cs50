#include <stdio.h>
#include <cs50.h>

/**
 * Prints a personalized message to the console.
 */
void printMessage(string sender, string recipient, string message);
 
int main(void)
{
  printf("Name of sender: ");
  string sender = GetString();

  printf("Name of recipient: ");
  string recipient = GetString();

  printf("Message: ");
  string message = GetString();

  printMessage(sender, recipient, message);
}

void printMessage(string sender, string recipient, string message)
{
    printf("Dear %s,\n\n", recipient);
    printf("%s\n\n", message);
    printf("Sincerly, %s\n", sender);
}
// TODO create a function called printMessage