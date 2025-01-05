#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Supprime les éléments de la liste chaînée dont les données
 * sont égales à `data_ref`, selon la fonction de comparaison `cmp`.
 *
 * @param begin_list Double pointeur vers le premier élément de la liste.
 * @param data_ref Donnée de référence à comparer.
 * @param cmp Fonction de comparaison qui retourne 0 si les deux paramètres sont égaux.
 */

typedef struct s_list
{
    struct s_list *next; // Pointeur vers le nœud suivant
    void          *data; // Données du nœud
} t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *))
{
    t_list *current;

    current = *begin_list;
    // Vérification des cas où la liste est vide ou n'existe pas
    if (begin_list == NULL || *begin_list == NULL)
        return;

    // Si le premier élément correspond, on le supprime
    if (cmp(current->data, data_ref) == 0)
    {
        *begin_list = current->next; // Passer au nœud suivant
        free(current);               // Libérer le nœud actuel
        ft_list_remove_if(begin_list, data_ref, cmp); // Vérifier le prochain nœud
    }
    else
    {
        // Continuer à parcourir la liste en vérifiant les nœuds suivants
        ft_list_remove_if(&(current->next), data_ref, cmp);
    }
}

// Fonction de comparaison utilisée dans ft_list_remove_if
int compare_strings(void *data1, void *data2)
{
    return strcmp((char *)data1, (char *)data2);
}

// Fonction pour créer un nouvel élément de liste
t_list *create_node(void *data)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Fonction pour ajouter un élément à la fin de la liste
void append_node(t_list **list, void *data)
{
    t_list *new_node = create_node(data);
    if (!new_node)
        return;

    if (*list == NULL)
    {
        *list = new_node;
    }
    else
    {
        t_list *current = *list;
        while (current->next)
            current = current->next;
        current->next = new_node;
    }
}

// Fonction pour afficher la liste
void print_list(t_list *list)
{
    while (list)
    {
        printf("%s -> ", (char *)list->data);
        list = list->next;
    }
    printf("NULL\n");
}

// Fonction pour libérer la liste
void free_list(t_list *list)
{
    t_list *tmp;
    while (list)
    {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

int main()
{
    t_list *list = NULL;

    // Création de la liste : "A -> B -> C -> B -> NULL"
    append_node(&list, "A");
    append_node(&list, "B");
    append_node(&list, "C");
    append_node(&list, "B");

    printf("Liste initiale :\n");
    print_list(list);

    // Suppression des nœuds contenant "B"
    char *data_ref = "B";
    printf("\nSuppression des nœuds contenant \"%s\"...\n", data_ref);
    ft_list_remove_if(&list, data_ref, compare_strings);

    printf("\nListe après suppression :\n");
    print_list(list);

    // Libération de la mémoire
    free_list(list);

    return 0;
}