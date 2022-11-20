#include "dictionary.h"

void    ft_sentence_generator(t_tree *tab_tree)
{
    if(ft_empty_trees(tab_tree))
    {
        printf("No trees had been generated. Please try to generate trees with a dictionary before.\n");
        return;
    }
	char modele;

	printf("Please enter a sentence model : ");
	scanf("\n%c", &modele);
    scanf("%*[^\n]");
    getchar();
	if (modele == '1')
	{
		ft_random_word(tab_tree[1]);
		ft_random_word(tab_tree[2]);
		ft_random_word(tab_tree[0]);
		ft_random_word(tab_tree[1]);
	}
	else if(modele == '2')
	{
		ft_random_word(tab_tree[1]);
		printf("qui ");
		ft_random_word(tab_tree[0]);
		ft_random_word(tab_tree[0]);
		ft_random_word(tab_tree[1]);
		ft_random_word(tab_tree[2]);
	}
	else if(modele == '3')
	{
		ft_random_word(tab_tree[1]);
		ft_random_word(tab_tree[0]);
		ft_random_word(tab_tree[3]);
		printf("avec ");
		ft_random_word(tab_tree[1]);
	}
	else
		printf("Please choose a valid model");
	printf("\n");
}