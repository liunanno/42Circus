#include <unistd.h>

void putnbr(int n)
{
    int nbr;

    putnbr(n / 10);
    nbr = (n % 10) + '0';
    write(1, &nbr, 1);
}

int main(int ac, char **av)
{
    (void)av;

    putnbr(ac - 1);
    write(1, "\n", 1);
    return (0):
}