#include "dictionary.h"

//initializes the table with the four trees for each type
void    ft_init_tab(t_tree *tab_tree)
{
    tab_tree[0] = createTree(createNode(-1));
    tab_tree[1] = createTree(createNode(-1));
    tab_tree[2] = createTree(createNode(-1));
    tab_tree[3] = createTree(createNode(-1));
    return;
}

//initializes the struct t_mot
void ft_init_mot(t_mot *mot)
{
    mot ->temps = NULL;
	mot ->genre = 0;
	mot ->nombre = 0;
	mot ->personne = 0;
	mot ->base = NULL;
	mot ->mot = NULL;
}

//create a tree
t_tree   createTree(t_node *node)
{
    t_tree tree;
    tree.root = node;
    return(tree);
}

//create a node
t_node    *createNode(char lettre)
{
    t_node *node;
    node = malloc(sizeof(t_node));
    node ->lettre = lettre;
    node ->liste_flechie = NULL;
    for(int i = 0; i < 26; i++)
        node ->tab_node[i] = NULL;
    return(node);
}
