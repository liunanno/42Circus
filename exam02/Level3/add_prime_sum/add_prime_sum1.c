#include <unistd.h>

int atoi(char *s)
{
    int res;
    
    res = 0;
    while(*s)
        res = res * 10 + *s++ - 48;
    return (res);
}

void put_nbr(int n)
{
    int nbr;
    if (n >= 10)
        put_nbr(n / 10);
    nbr = n % 10 + '0';
    write(1, &nbr, 1);
}

int is_prime(int num)
{
    int i;

    i = 2;
    if (num <= 1)
        return (0);
    while (i * i <= num)
    {
        if (num % i == 0)
            return (0);
            i++;    
    }
    return (1);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int nbr;
        int sum;

        nbr = atoi(av[1]);
        sum = 0;
        while (nbr > 0)
        {
            if (is_prime(nbr))
                sum += nbr;
            nbr--;
        }
        put_nbr(sum);
    }
    write(1, "\n", 1);
}