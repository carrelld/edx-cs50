#include <stdio.h>
#include <cs50.h>

int gcd_iter(int u, int v) {
  int t;
  while (v) {
    t = u; 
    u = v; 
    v = t % v;
  }
  return u < 0 ? -u : u; /* abs(u) */
}

int gcd(int u, int v) {
return (v != 0)?gcd(v, u%v):u;
}


int main(void) {
    printf("First number: ");
    int x = GetInt();
    printf("Second number: ");
    int y = GetInt();
    
    int choice;
    do {
        printf("Computation method (1 or 2)");
        choice = GetInt();
    } while(!(choice == 1 || choice == 2));

    
    switch (choice) {
        case 1:
            printf("GCD via interation is %d\n", gcd_iter(x, y));
            break;
        case 2:
            printf("GCD via recusion is %d\n", gcd(x, y));
        default:
            break;
    }
}

