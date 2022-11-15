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

void    ft_random_word(t_tree tree)
{
    char random_word[30];
    t_node *node = tree.root;
    int i;
    int j = 0;

    srand((unsigned)time(NULL));
    i = rand() %28;
    while (node ->tab_node[i] == NULL)
    {
        i = rand() %28;
    }
    node = node ->tab_node[i];
    while (!ft_verif_end(node))
    {
        random_word[j] = node ->lettre;
        if (node ->tab_node[i])
        {
            node = node ->tab_node[i];
            j++;
        }
        i = rand() %28;
    }
    random_word[j++] = node ->lettre;
    random_word[j++] = 0;
    printf("Mot trouvé : %s\n", random_word);
}