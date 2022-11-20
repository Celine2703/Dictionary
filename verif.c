#include "dictionary.h"

//verif if the node is the end of a word. if it's the end of a word, the function chooses randomly to return 1 or 0 (used for random generated word)
int ft_verif_end(t_node *node)
{
    if (node ->liste_flechie == NULL)
        return (0);
    else
    {
        if (rand() %10 == 0)
            return (1);
        else
            return (0);
    }
}

//check if it 's a leaf
int ft_leaf(t_node *node)
{
    for (int i = 0; i < 28; i++)
    {    
        if (node ->tab_node[i])
            return (0);
    }
    return (1);
}

//check if there is at least one tree generated or none
int ft_empty_trees(t_tree *tab_tree)
{
    for (int i = 0; i < 4; i++)
    {
        if (ft_leaf(tab_tree[i].root) != 1)
            return (0);
    }
    return (1);
}