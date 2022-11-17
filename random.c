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

void ft_random_base(t_tree *tab_tree)
{
    int vide = 1;
    srand((unsigned)time(NULL));
    for (int i = 0; i < 4; i++)
    {
        if (ft_leaf(tab_tree[i].root) != 1)
            vide = 0;
    }
    if (vide)
    {
        printf("No trees had been generated. Please try to generate trees with a dictionary before.\n");
        return;
    }
    int random_tree = rand()%4;
    while (ft_leaf(tab_tree[random_tree].root) == 1)
        random_tree = rand()%4;
    ft_random_word(tab_tree[random_tree]);
}