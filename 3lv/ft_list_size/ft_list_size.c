#include "ft_list_size.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	return (1 + ft_list_size(begin_list->next));
}

t_list	*create_node(int value)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = (void *)(long)value;
	new_node->next = NULL;
	return(new_node);
}

int	main(void)
{
	t_list *lst = NULL;
	t_list *tmp = NULL;
	int	listlen;
	
	lst = create_node(1);
	lst->next = create_node(2);
	lst->next->next = create_node(3);
	
	listlen = ft_list_size(lst);
	printf("Voici : %d\n", listlen);

	while (lst != NULL)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	return (0);
}
