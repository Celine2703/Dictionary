#include "dictionary.h"

int main()
{
    FILE *fp;
    char mot[100];
    char base[100];
    char flechies[100];
    t_recup data;
    t_tree tree = ft_init_verbe();
    fp = fopen("./dico_10_lignes.txt", "r");
    if (fp == NULL)
        return (1);
    while (fscanf(fp, "%s %s %s", mot, base, flechies) != EOF)
    {
        printf("%s, %s, %s\n", mot, base, flechies);
        data.base = base;
        data.mot = mot;
        data.flechie = flechies;
        data.arbre = ft_choose(flechies);
        ft_remplit(data, tree);
    }
    ft_display(tree.root);
    fclose(fp);
}