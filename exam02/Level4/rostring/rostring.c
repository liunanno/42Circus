#include <unistd.h>
#include <stdlib.h>

void    rostring(char *str)
{
    int i;
    int start;
    int end;
    int flag;

    flag = 0;
    i = 0;
    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        start = i;
        while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
            i++;
        end = i;
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        while (str[i])
        {
            while ((str[i] == ' ' || str[i] == '\t') && (str[i + 1] == ' ' || str[i + 1] == '\t'))
                i++;
            if (str[i] == ' ' || str[i] == '\t')
                flag = 1;
            write(1, &str[i], 1);
            i++;
        }
        if (flag == 1)
            write(1, " ", 1);
        while (start < end)
        {
            write(1, &str[start], 1);
            start++;
        }
    }
}

int main(int ac, char **av)
{
    if (ac > 1)
        rostring(av[1]);
    write(1, "\n", 1);
    return (0);
}