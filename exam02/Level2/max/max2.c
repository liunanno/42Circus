int max(int *tab, unsigned int len)
{
    unsigned int i;
    unsigned int result;

    i = 0;
    result = tab[i];
    if (len == 0)
        return (0);
    while(i < len)
    {
        if (result < tab[i])
            result = tab[i];
        i++;
    }
    return (result);
}