#include "ft_list.h"
#include <stddef.h>

int ft_list_size(t_list *begin_list)
{
    int count = 0;
    t_list *curr = begin_list;

    while (curr != NULL)
    {
        count++;
        curr = (t_list*)curr->next; // 对next进行类型转换
    }

    return count;
}