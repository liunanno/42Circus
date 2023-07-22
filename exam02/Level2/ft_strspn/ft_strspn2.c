size_t ft_strspn(const char *s, const char *accept)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (s[i])
    {
        j = 0;
        while (accept[j])
        {
            if (accept[j] == s[i])
                break;
            j++;
        }
        if (!accept[j])
            return (i);
        i++;
    }
    return (i);
}