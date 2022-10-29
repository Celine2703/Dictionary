#include <stdlib.h>
#include "dictionary.h"

void    ft_init()
{
	t_tree verbe = *ft_init_tree();
	t_tree nom = *ft_init_tree();
	t_tree adj = *ft_init_tree();
	t_tree adv = *ft_init_tree();
}

t_tree	*ft_init_tree()
{
    t_tree	*tab;
    char	lettre;

    tab = malloc(sizeof (t_tree) * 26);
    lettre = 'a';
    for(int i = 0; i < 26; i++)
    {
        tab[i] = createTree(createNode(lettre));
        lettre++;
    }
    return (tab);
}

t_tree   createTree(t_node *node)
{
    t_tree tree;
    tree.root = node;
    return(tree);
}

t_node	*createNode(char lettre)
{
	t_node *node;
    node = malloc(sizeof(t_node));
    node ->lettre = lettre;
    node ->liste_flechie = NULL;
    for(int i = 0; i < 26; i++)
        node ->tab_node[i] = NULL;
    return(node);
}