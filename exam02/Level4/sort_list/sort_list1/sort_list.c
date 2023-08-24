#include "list.h"

t_list  *sort_list(t_list *lst, int (*cmp)(int, int))
{
    int tmp;
    t_list  *i;
    t_list  *j;

    i = lst;
    while (i != NULL)
    {
        j = i -> next;
        while (j != NULL)
        {
            if ((*cmp)(i -> data, j -> data))
            {
                tmp = i -> data;
                i -> data = j -> data;
                j -> data = tmp;
            }
            j = j -> next;
        }
        i = i -> next;
    }
    return (lst);
}