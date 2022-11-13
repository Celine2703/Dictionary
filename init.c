#include "dictionary.h"

t_tree    ft_init_verbe()
{
    t_tree tab_verbe;
    tab_verbe = createTree(createNode(-1));
    return (tab_verbe);
}

void ft_init_mot(t_mot *mot)
{
    mot ->temps = NULL;
	mot ->genre = 0;
	mot ->nombre = 0;
	mot ->personne = 0;
	mot ->base = NULL;
	mot ->mot = NULL;
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

t_list *createFlechie(t_list *list, t_recup data)
{
    t_list *temp = list;
    if (list == NULL)
    {
        list = malloc(sizeof(t_list));
        list ->mot = createMot(data);
        list ->next = NULL;
    }
    else
    {
        while (list != NULL)
        {
            temp = list;
            list = list ->next;
        }
        temp ->next = malloc(sizeof(t_list));
        temp ->next ->mot = createMot(data);
        temp ->next ->next = NULL;
    }
    return (list);
}

t_mot *createMot(t_recup data)
{
    t_mot *mot = malloc(sizeof(t_mot));
    char **split = ft_split(data.flechie + 4, '+');
    ft_init_mot(mot);
    if (data.arbre == 1)
    {
        if(split[0])
        {
            mot ->temps = split[0];
            if(split[1])
            {
                mot ->nombre = split[1][0];
                if(split[2] && split[2][0] && split[2][1])
                    mot ->personne = split[2][1];
            }
        }
    }
    ft_clear_split(split);
    return (mot);
}