#include <unistd.h>

void    rstr_capitalizer(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
    i = 0;
    while (str[i])
    {
        if ((str[i] >= 'a' && str[i] <= 'z') && (str[i + 1] == ' ' \
        || str[i + 1] == '\t' || str[i + 1] == '\0'))
            str[i] -= 32;
        i++;
    }
    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int main(int ac, char **av)
{
    int i;

    i = 1;
    if (ac == 2)
    {
        while (av[i])
        {
            rstr_capitalizer(av[i]);
            write(1, "\n", 1);
            i++;
        }
    }
    else
        write(1 ,"\n", 1);
}