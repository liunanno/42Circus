#include <stdlib.h>

static int  get_len(int nbr)
{
    int len;

    len = 0;
    if (nbr <= 0)
        len++;
    while (nbr != 0)
    {
        nbr = nbr / 10;
        len++;
    }
    return (len);
}

char    *ft_itoa(int nbr)
{
    char    *str;
    long    n;
    int len;

    n = nbr;
    len = get_len(n);
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    result[len] = '\0';
    if (nbr == 0)
    {
        result[0] = '0';
        return (result);
    }
    if (nbr < 0)
    {
        result[0] = '-';
        nbr = -nbr;
    }
    while (nbr)
    {
        result[--len] = nbr % 10 + '0';
        nbr /= 10;
    }
    return (result);
}