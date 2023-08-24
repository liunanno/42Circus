void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int tmp;
    int i;

    i = 0;
    while (i < (size - 1))
    {
        if (tab[i + 1] < tab[i])
        {
            tmp = tab[i + 1];
            tab[i + 1] = tab[i];
            tab[i] = tmp;
            i = 0;
        }
        else
            i++;
    }
}