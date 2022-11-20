#include "dictionary.h"

//generates a random base word and prints it
void    ft_random_word(t_tree tree)
{
    char random_word[30];
    t_node *node = tree.root;
    int i;
    int j = 0;

    i = rand() %28; //choose an integer between 0 and 27
    while (node ->tab_node[i] == NULL)
    {
        i = rand() %28;
    }
    node = node ->tab_node[i];
    while (!ft_verif_end(node)) //until an end of a word is reached, the function reaches a random child node
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
    printf("%s ", random_word);
}

//Select a tree randomly
void ft_random_base(t_tree *tab_tree)
{
    if(ft_empty_trees(tab_tree))
    {
        printf("No trees had been generated. Please try to generate trees with a dictionary before.\n");
        return;
    }
    int random_tree = rand()%4;
    while (ft_leaf(tab_tree[random_tree].root) == 1)
        random_tree = rand()%4;
    printf("Mot trouvé : ");
    ft_random_word(tab_tree[random_tree]);
    printf("\n");
}