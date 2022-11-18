#include "dictionary.h"

int ft_base_in_tree(t_tree tree, char *str_to_search)
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
    if (str_to_search[i] == 0 && node ->liste_flechie)
        return (1);
    return (0);
}

void ft_base_search(t_tree *tab_tree)
{
    char base_word[30];
    char classe[10];

    printf("Which base? ");
    scanf("\n%s", base_word);
    scanf("%*[^\n]");
    getchar();
    do{
        printf("Which class? (Ver, Nom, Ajd, Adv or All). Please don't forget the uppercases : ");
        scanf("\n%s", classe);
        scanf("%*[^\n]");
        getchar();
    } while (!ft_choose(classe) && strncmp("All", classe,  4));
    if (!strncmp(classe, "All", 4))
    {
        for (int i = 0; i < 4; i++)
        {
            if (ft_base_in_tree(tab_tree[i], base_word))
            { 
                printf("The word %s has been found !\n", base_word);
                return;
            }
        }
        printf("The word %s hasn't been found\n", base_word);
    }
    else
    {
        if (ft_base_in_tree(tab_tree[ft_choose(classe) - 1], base_word))
            printf("The word %s has been found !\n", base_word);
        else
            printf("The word %s hasn't been found !\n", base_word);
    }
}