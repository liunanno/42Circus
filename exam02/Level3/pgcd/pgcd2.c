#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int nbr1;
    int nbr2;
    int pgcd;

    if (ac == 3)
    {
        if ((nbr1 = atoi(av[1])) > 0 && (nbr2 = atoi(av[2])) > 0)
        {
            if (nbr1 <= nbr2)
                pgcd = nbr1;
            else
                pgcd = nbr2;
            }
        while ((nbr1 % pgcd != 0) || (nbr2 % pgcd != 0))
            pgcd--;
        printf("%d", pgcd);
    }
    printf("\n");
    return (0);
}