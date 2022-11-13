#include "dictionary.h"

//choose which tree based on the data of the word(verb, noun, etc...)
int ft_choose(char *flechie)
{
    //use of the function strncmp in string.h -> strncmp(first string, second string, number of bytes compared)
    if (!strncmp(flechie, "Ver", 3))
        return (1);
    else if (!strncmp(flechie, "Nom", 3))
        return (2);
    else if (!strncmp(flechie, "Adj", 3))
        return (3);
    else if (!strncmp(flechie, "Adv", 3))
        return (4);
    return (0);
}

//put the base and the word in the tree
int ft_remplit(t_recup data, t_tree *tree)
{
    int i = 0;
    t_node *node = tree[data.arbre - 1].root;
    //put the base in the tree letter by letter
    while (data.base[i] != 0)
    {
        if (node ->tab_node[data.base[i] - 'a'] == NULL)
            node ->tab_node[data.base[i] - 'a'] = createNode(data.base[i]);
        node = node ->tab_node[data.base[i] - 'a'];
        i++;
    }
    //put the word in a list in the last letter of the base
    node ->liste_flechie = createFlechie(node ->liste_flechie, data);
    return (0);
}

void ft_display(t_node *node)
{
    if (node ->lettre != -1)
        printf("%c ", node ->lettre);
    if (node ->liste_flechie)
    {
        display_f(node ->liste_flechie);
    }
    for (int i = 0; i<26; i++)
    {
        if (node ->tab_node[i])
            ft_display(node ->tab_node[i]);
    }
    
}

void display_f(t_list *list)
{
    printf("\n flechies :\n");
    while (list)
    {
        printf("%s\n", list ->mot ->mot);
        list = list ->next;
    }
}