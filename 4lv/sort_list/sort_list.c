#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int		swap;
	t_list	*start;

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
int	ascending(int a, int b)
{
	return (a <= b);
}

t_list	*create_node(int value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
	{
		exit(EXIT_FAILURE);
	}
	node->data = value;
	node->next = NULL;
	return (node);
}

// ajouter un nouveau nœud à la fin d'une liste chaînée
void	add_node(t_list **mylist, int value)
{
	t_list	*new_node;
	t_list	*temp;

	new_node = create_node(value);
	// si la liste est vide
	if (*mylist == NULL)
	{
		*mylist = new_node;
		return ;
	}
	// si la liste n'est pas vide
	temp = *mylist;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
}

void	print_list(t_list *mylist)
{
	while (mylist != NULL)
	{
		printf("%d -> ", mylist->data);
		mylist = mylist->next;
	}
	printf("NULL\n");
}

// Fonction pour afficher la liste avec les adresses mémoire
void print_list_with_addresses(t_list *head) 
{
    printf("Adresse du pointeur principal (tête de liste) : %p\n", (void *)head);
    while (head != NULL) {
        printf("[Adresse : %p, Valeur : %d, Suivant : %p] -> \n", 
               (void *)head, 
               head->data, 
               (void *)head->next);
        head = head->next;
    }
    printf("NULL\n");
}

int	main(void)
{
	t_list	*mylist;
	t_list	*temp;

	mylist = NULL;
	add_node(&mylist, 3);
	add_node(&mylist, 1);
	add_node(&mylist, 4);
	add_node(&mylist, 2);

	printf("Liste avant tri : \n");
	print_list(mylist);

	// tri ordre croissant
	mylist = sort_list(mylist, ascending);
	printf("Liste apres tri : \n");
	print_list(mylist);

    printf("Liste après tri (avec adresses mémoire) :\n");
    print_list_with_addresses(mylist);
	
    // free
	while (mylist != NULL)
	{
		temp = mylist;
		mylist = mylist->next;
		free(temp);
	}
	return (0);
}
*/