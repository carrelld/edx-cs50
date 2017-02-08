/**
 * Purpose: Same function as ex1 but using a function to increase readability
 * Date: 2016/01/22
 * Author: David Carrell
 */

#include <stdio.h>
#include <cs50.h>

void transfer(float *sender, float *recipient, float amount)
{
    *recipient += amount;
    *sender -= amount;
}

int main(void)
{
    float bank = 0, jack = 20, jill = 0, franklin = 0, sally = 0;
    transfer(&jack, &bank, 3.75);
    transfer(&jack, &jill, 5.23);
    transfer(&jill, &bank, 1.4);
    transfer(&jill, &franklin, 2.0);
    transfer(&jack, &franklin, 4.05);
    transfer(&franklin, &sally, franklin / 3.0);
    
    // float jack = 20.0;
    // jack = jack - 3.75;
    // jack = jack - 5.23;
    // float jill = 5.23;
    // jill -= 1.4;
    // jill -= 2.0;
    // float franklin = 2.0;
    // jack -= 4.05;
    // franklin += 4.05;
    // float sally = franklin * .333333;
    // franklin -= franklin * .333333;
    
    printf("Jack $%.2f, Jill $%.2f, Franklin $%.2f, Sally $%.2f\n", jack, jill, franklin, sally);
    float avg = (jack + jill + franklin + sally) / 4.0;
    printf("Their average is $%.2f\n", avg);
}