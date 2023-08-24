#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    // 创建链表
    t_list *list = malloc(sizeof(t_list));
    int data1 = 1;
    list->data = &data1;
    t_list *node2 = malloc(sizeof(t_list));
    int data2 = 2;
    node2->data = &data2;
    list->next = node2;
    t_list *node3 = malloc(sizeof(t_list));
    int data3 = 3;
    node3->data = &data3;
    node2->next = node3;
    node3->next = NULL;

    // 计算链表节点数目
    int size = ft_list_size(list);

    // 输出结果
    printf("List size: %d\n", size);

    // 释放链表内存
    free(node3);
    free(node2);
    free(list);

    return 0;
}