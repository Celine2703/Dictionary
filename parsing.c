#include "dictionary.h"

int ft_choose(char *str)
{
    if (!strncmp(str, "Ver", 3))
        return (1);
    else if (!strncmp(str, "Nom", 3))
        return (2);
    else if (!strncmp(str, "Adj", 3))
        return (3);
    else if (!strncmp(str, "Adv", 3))
        return (4);
    return (0);
}

int ft_remplit(t_recup data, t_tree tree)
{
    int i = 0;
    t_node *node = tree.root;
    while (data.base[i] != 0)
    {
        if (node ->tab_node[data.base[i] - 'a'] == NULL)
            node ->tab_node[data.base[i] - 'a'] = createNode(data.base[i]);
        node = node ->tab_node[data.base[i] - 'a'];
        i++;
    }
    node ->liste_flechie = createFlechie(node ->liste_flechie, data);
    return (0);
}

void ft_display(t_node *node)
{
    if (node ->lettre != -1)
        printf("%c ", node ->lettre);
    for (int i = 0; i<26; i++)
    {
        if (node ->tab_node[i])
            ft_display(node ->tab_node[i]);
    }
    //printf("\n");
}