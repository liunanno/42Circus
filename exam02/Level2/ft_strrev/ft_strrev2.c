char *ft_strrev(char *str)
{
    int i;
    int len;
    char temp;

    i = -1;
    len = 0;
    while(str[len])
        len++;
    while(++i < len / 2)
    {
        temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
    return (str);
}