#include <stdio.h>

size_t  ft_strcspn(const char *s, const char *reject)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(s[i])
    {
        j = 0;
        while (reject[j])
        {
            if (reject[j] == s[i])
                return (i);
            j++;
        }
        i++;
    }
    return (i);
}

int main()
{
    char *s1 = "agsdagasdg";
    char *s2 = "ag";
    printf("%zu", ft_strcspn(s1, s2));
}