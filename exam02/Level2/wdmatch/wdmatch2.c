#include <unistd.h>

void    putstr(const char *str)
{
    int i;

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
    int j;

    i = 0;
    j = 0;
    if (ac == 3)
    {
        while (av[2][j])
            if (av[2][j++] == av[1][i])
                i++;
        if (!av[1][i])
            putstr(av[1]);
    }
    write(1, "\n", 1);
    return (0);
}