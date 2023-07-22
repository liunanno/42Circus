#include <stdio.h>
#include <string.h>

size_t  ft_strspn(const char *s, const char *accept)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (accept[i])
    {
        j = 0;
        while (s[j])
        {
            if (s[j] == accept[i])
                break;
            j++;
        }
        if (!s[j])
            return (i);
        i++;
    }
    return (i);
}

int main() {
    char str[] = "123456789";
    char accept[] = "123456";
    size_t count = ft_strspn(str, accept);
    printf("The number of digits in the prefix of \"%s\" is %zu\n", str, count);
    return 0;
}