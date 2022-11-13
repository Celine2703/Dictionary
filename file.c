#include "dictionary.h"

int main()
{
    FILE *fp;
    char mot[30];
    char base[30];
    char flechies[30];
    t_recup data;
    t_tree tab_tree[4];

    ft_init_tab(tab_tree);
    fp = fopen("./dico_10_lignes.txt", "r"); //use of the function fopen
    if (fp == NULL)
        return (1);
    //put the data in the t_recup struc and then in the tree 
    while (fscanf(fp, "%s %s %s", mot, base, flechies) != EOF)
    {
        //printf("%s, %s, %s\n", mot, base, flechies);
        data.base = base;
        data.mot = mot;
        data.flechie = flechies;
        data.arbre = ft_choose(flechies);
        ft_remplit(data, tab_tree); //put the data in the tree
    }
    fclose(fp);
}