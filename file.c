#include "dictionary.h"

int main(int argc, char **argv)
{
    if (argc != 2) //ne prend qu'un seul fichier dictionnaire
        return (0);
    FILE *fp; //FILE pointer to access a file
    char mot[30];
    char base[30];
    char flechies[100];
    t_data *data = malloc(sizeof(t_data));
    t_tree tab_tree[4];

    ft_init_tab(tab_tree);
    fp = fopen(argv[1], "r"); //use of the function fopen with the mode read only
    if (fp == NULL)
        return (perror("Erreur ouverture de fichier\n"), errno);
    
    //put the data in the t_data struct and then in the tree
    while (fscanf(fp, "%s %s %s", mot, base, flechies) != EOF) //EOF = End Of File
    {
        if (ft_choose(flechies)) //If it's a word we have to consider (verbe, noun, adj or adv)
        {
            data ->base = base;
            data ->mot = mot;
            data ->flechie = flechies;
            data ->arbre = ft_choose(flechies); //to know in which tree putting the data
            ft_put_data(*data, tab_tree); //put the data in the tree
        }
    }
    //diplay the trees
    ft_display(tab_tree[0].root);
    printf("\n");
    ft_display(tab_tree[1].root);
    printf("\n");
    ft_display(tab_tree[2].root);
    printf("\n");
    ft_display(tab_tree[3].root);

    //random base word
    srand((unsigned)time(NULL));
    int random_tree = rand()%4;
    while (ft_leaf(tab_tree[random_tree].root) == 1)
        random_tree = rand()%4;
    ft_random_word(tab_tree[random_tree]);
    free(data);
    ft_clear_tree(tab_tree, 4);
    fclose(fp);
    return (0);
}