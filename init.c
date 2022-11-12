#include "dictionary.h"

t_tree    ft_init_verbe()
{
    t_tree tab_verbe;
    tab_verbe = createTree(createNode(-1));
    return (tab_verbe);
}

t_tree   createTree(t_node *node)
{
    t_tree tree;
    tree.root = node;
    return(tree);
}

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

t_list *createFlechie(t_list *list, char *str)
{
    t_list *temp = list;
    if (list == NULL)
    {
        list ->mot = createMot(str);
        list ->next = NULL;
    }
    else
    {
        while (list != NULL)
        {
            temp = list;
            list = list ->next;
        }
        temp ->next -> mot = createMot(str);
        temp ->next ->next = NULL;
    }
    return (list);
}

t_mot createMot(char *str)
{
    
}