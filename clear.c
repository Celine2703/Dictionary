#include "dictionary.h"

//clear a table of strings
void	ft_clear_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
        free(str[i++]);
	free(str);
	str = 0;
}

//clear a t_mot structure
void	ft_clear_mot(t_mot *mot)
{
    free(mot ->temps);
    free(mot ->base);
    free(mot ->mot);
    free(mot);
}

//clear a t_list
void	ft_clear_list(t_list *list)
{
	t_list	*temp;

	if (!list)
		return ;
	while (list)
	{
		temp = list ->next;
        ft_clear_mot(list ->mot);
        free(list);
		list = temp;
	}
}

//clear a t_node
void    ft_clear_node(t_node *node)
{
    for (int i = 0; i < 28; i++)
    {
        if (node ->tab_node[i])
            ft_clear_node(node ->tab_node[i]);
    }
    if (node ->liste_flechie)
        ft_clear_list(node ->liste_flechie);
    free(node);
}

//clear a table of t_tree
void    ft_clear_tree(t_tree *tree, int size)
{
    for (int i = 0; i < size; i++)
        ft_clear_node(tree[i].root);
}