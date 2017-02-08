#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float jack = 20.0;
    jack = jack - 3.75;
    jack = jack - 5.23;
    float jill = 5.23;
    jill -= 1.4;
    jill -= 2.0;
    float franklin = 2.0;
    jack -= 4.05;
    franklin += 4.05;
    float sally = franklin * .333333;
    franklin -= franklin * .333333;
    
    printf("Jack $%.2f, Jill $%.2f, Franklin $%.2f, Sally $%.2f\n", jack, jill, franklin, sally);
    float avg = (jack + jill + franklin + sally) / 4.0;
    printf("Their average is $%.2f\n", avg);
}