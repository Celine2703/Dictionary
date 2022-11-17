#include "dictionary.h"

void ft_base_in_tree(t_tree tree, char *str_to_search)
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

void ft_base_search(t_tree *tab_tree)
{
    char base_word[30];
    char classe[10];

    printf("quelle base? ");
    scanf("\n%s", base_word);
    scanf("%*[^\n]");
    getchar();
    do{
        printf("quelle classe? (Ver, Nom, Ajd or Adv). Please don't forget the uppercases : ");
        scanf("\n%s", classe);
        scanf("%*[^\n]");
        getchar();
    } while (!ft_choose(classe));
    ft_base_in_tree(tab_tree[ft_choose(classe) - 1], base_word);
}