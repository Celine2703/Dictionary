#include "dictionary.h"

void ft_base_search(t_tree tree, char *str_to_search)
{
    t_node *node = tree.root;
    int i = 0;
    int j = 0;

    while(!ft_leaf(node) && j < 28 && str_to_search[i])
    {
        if (node ->tab_node[j] && node ->tab_node[j] ->lettre == str_to_search[i])
        {
            node = node ->tab_node[j];
            i++;
            j = 0;
        }
        else
            j++;
    }
    if (str_to_search[i] == 0)
        printf("mot %s trouvé\n", str_to_search);
    else
        printf("mot %s non trouvé\n", str_to_search);
}