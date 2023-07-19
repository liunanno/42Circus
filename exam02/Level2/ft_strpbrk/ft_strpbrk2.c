#include <string.h>
#include <stdio.h>

char *ft_strpbrk(const char *s1, const char *s2)
{
    int i = 0;
    int j = 0;
    if (!s1 || !s2)
    {
        return (0);
    }
    while (s1[i])
    {
        j = 0;
        while (s2[j])
        {
            if (s1[i] == s2[j])
                return (char s1[i]);
            j++;
        }
        i++;
    }
    return (0);
}

int main() {
    char str[] = "hello world";
    char *result = ft_strpbrk(str, "aeiou");
    if (result != NULL) {
        printf("Found vowel '%c' at index %ld.\n", *result, result - str);
    } else {
        printf("No vowels found.\n");
    }
    return 0;
}