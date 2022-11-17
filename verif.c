#include "dictionary.h"

int ft_verif_end(t_node *node)
{
    if (node ->liste_flechie)
        return (1);
    return (0);
}

int ft_leaf(t_node *node)
{
    for (int i = 0; i < 28; i++)
    {    
        if (node ->tab_node[i])
            return (0);
    }
    return (1);
}

int ft_empty_trees(t_tree *tab_tree)
{
    for (int i = 0; i < 4; i++)
    {
        if (ft_leaf(tab_tree[i].root) != 1)
            return (0);
    }
    return (1);
}