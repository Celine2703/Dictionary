#include <stdlib.h>
#include "dictionnaire.h"

void    ft_init_verbe()
{
    t_tree_verbe *tab_verbe;
    char lettre;
    tab_verbe = malloc(sizeof (t_tree_verbe) * 26);
    lettre = 'a';
    for(int i = 0; i < 26; i++)
    {
        tab_verbe[i] = createTreeVerbe(createNodeVerbe(lettre));
        lettre++;
    }
}

t_tree_verbe   *createTreeVerbe(t_node_verbe *node)
{
    t_tree_verbe *tree;
    tree = malloc(sizeof(t_tree_verbe));
    tree ->root = node;
    return(tree);
}

t_node_verbe    *createNodeVerbe(char lettre)
{
    t_node_verbe *node;
    node = malloc(sizeof(t_node_verbe));
    node ->lettre = lettre;
    node ->liste_flechie = NULL;
    return(node);
}