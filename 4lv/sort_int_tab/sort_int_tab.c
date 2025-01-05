#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i = 0;
	int	temp;

	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i+ 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

int main(void)
{
    int tab[] = {5, 2, 9, 1, 5, 6};
    unsigned int size = sizeof(tab) / sizeof(tab[0]);

    printf("Tableau avant tri : ");
    for (unsigned int i = 0; i < size; i++)
        printf("%d ", tab[i]);
    printf("\n");

    sort_int_tab(tab, size);

    printf("Tableau après tri : ");
    for (unsigned int i = 0; i < size; i++)
        printf("%d ", tab[i]);
    printf("\n");

    return 0;
}
