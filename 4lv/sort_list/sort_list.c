#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
    int data;
    struct s_list *next;
} t_list;

t_list  *sort_list(t_list *lst, int (*cmp)(int, int))
{
    int swap;
    t_list  *start;

    start = lst;  
    while (lst != NULL && lst->next != NULL)
    {
        if((*cmp)(lst->data, lst->next->data) == 0)
        {
            swap = lst->data;
            lst->data = lst->next->data;
            lst->next->data = swap;
            lst = start;
        }
        else
            lst = lst->next;
    }
    return (start);
}
/*
int ascending(int a, int b)
{
    return (a <= b);
}

t_list  *create_node(int value)
{
    t_list  *node;

    node = malloc(sizeof(t_list));
    if (!node)
    {
        exit(EXIT_FAILURE);
    }
    node->data = value;
    node->next = NULL;
    return (node);
}
*/