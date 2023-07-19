char *ft_strrev(char *str)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while(*str)
    {
        i++;
        len++;
    }
    
    char str1[len];
    while (len >= 0)
    {
        str1[i] = str[len - i];
        i--;
    }
    return (str1);
}