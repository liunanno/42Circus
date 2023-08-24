#include <stdio.h>
#include <stdlib.h>

unsigned int    lcm(unsigned int a, unsigned int b)
{
    unsigned int lcm;

    lcm = 1;
    if (a == 0 || b == 0)
        return (0);
    while (lcm % a != 0 || lcm % b != 0)
        lcm++;
    return (lcm);
}

int main(int ac, char **av)
{
    int a, b;
    a = atoi(av[1]);
    b = atoi(av[2]);
    if (ac == 3)
        printf("%d", lcm(a, b));
    printf("\n");
}