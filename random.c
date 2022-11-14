#include "dictionary.h"

int ft_verif_end(t_node *node)
{
    if (node ->liste_flechie)
        return (1);
    return (0);
}

void    ft_random_word(t_tree tree)
{
    char random_word[30];
    t_node *node = tree.root;
    int i;
    int j = 0;

    i = rand() %26;
    while (node ->tab_node[i] == NULL)
    {
        i = rand() %26;
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
        i = rand() %26;
    }
    random_word[j++] = node ->lettre;
    random_word[j++] = 0;
    printf("Mot trouvé : %s\n", random_word);
}