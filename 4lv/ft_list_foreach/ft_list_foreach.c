#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>


void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    while (begin_list)
    {
        (*f)(begin_list->data);
        begin_list = begin_list->next;
    }
}

// Fonction pour afficher un entier
void print_int(void *data)
{
    printf("%d\n", *(int *)data);
}

// Fonction pour doubler un entier
void double_int(void *data)
{
    *(int *)data *= 2;
}

// Fonction pour créer un nouvel élément de la liste
t_list *ft_create_elem(void *data)
{
    t_list *new_elem = (t_list *)malloc(sizeof(t_list));
    if (!new_elem)
        return NULL;
    new_elem->data = data;
    new_elem->next = NULL;
    return new_elem;
}

// Fonction pour ajouter un élément à la fin de la liste
t_list *ft_list_push_back(t_list *list, void *data)
{
    t_list *new_elem = ft_create_elem(data);
    if (!list)
        return new_elem;

    t_list *temp = list;
    while (temp->next)
        temp = temp->next;
    temp->next = new_elem;
    return list;
}

int main()
{
    // Création d'une liste chainée
    t_list *list = NULL;
    int a = 1, b = 2, c = 3;

    list = ft_list_push_back(list, &a);
    list = ft_list_push_back(list, &b);
    list = ft_list_push_back(list, &c);

    // Affichage de la liste avant modification
    printf("Liste avant modification :\n");
    ft_list_foreach(list, print_int);

    // Application de la fonction double_int
    ft_list_foreach(list, double_int);

    // Affichage de la liste après modification
    printf("\nListe après modification :\n");
    ft_list_foreach(list, print_int);

    // Libération de la mémoire
    while (list)
    {
        t_list *temp = list;
        list = list->next;
        free(temp);
    }

    return 0;
}
