#include <unistd.h>

void    putnbr(int n)
{
    int nbr;

    if (n >= 10)
    {
        putnbr (n / 10);
        nbr = n % 10 + '0';
        write(1, %nbr, 1);
    }
}

int atoi(char *str)
{
    int nbr;

    nbr = 0;
    while (*str)
    {
        nbr = 10 * nbr + *str++ - 'A' + '0';
    }
    return (nbr);
}

int is_prime(int n)
{
    int i;

    i = 2;
    if (n <= 1)
        return (0);
    while (i * i <= n)
    {
        if (num % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int main(int ac, char **av)
{
    int sum;
    int num;

    sum = 0;
    num = atoi(av[1]);
    if (ac == 2)
    {
        while(num > 0)
        {
            if (is_prime(num))
                sum += num;
            num--;
        }
        putnbr(sum);
    }
    write(1, "\n", 1);
    return (0);
}