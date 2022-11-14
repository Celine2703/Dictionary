#include "dictionary.h"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (0);
    FILE *fp;
    char mot[30];
    char base[30];
    char flechies[30];
    t_data data;
    t_tree tab_tree[4];

    ft_init_tab(tab_tree);
    fp = fopen(argv[1], "r"); //use of the function fopen
    if (fp == NULL)
        return (1);
    //put the data in the t_recup struc and then in the tree 
    while (fscanf(fp, "%s %s %s", mot, base, flechies) != EOF)
    {
        data.base = base;
        data.mot = mot;
        data.flechie = flechies;
        data.arbre = ft_choose(flechies);
        ft_put_data(data, tab_tree); //put the data in the tree
    }
    //diplay the trees
    ft_display(tab_tree[0].root);
    printf("\n");
    ft_display(tab_tree[1].root);
    printf("\n");
    ft_display(tab_tree[2].root);
    printf("\n");
    ft_display(tab_tree[3].root);

    ft_random_word(tab_tree[0]);
    ft_clear_tree(tab_tree, 4);
    fclose(fp);
}