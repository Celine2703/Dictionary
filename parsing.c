#include "dictionary.h"

//choose which tree based on the data of the word(verb, noun, etc...)
int ft_choose(char *flechie)
{
    //use of the function strncmp in string.h 
    //-> strncmp(first string, second string, number of bytes compared)
    if (!strncmp(flechie, "Ver", 3))
        return (1);
    else if (!strncmp(flechie, "Nom", 3))
        return (2);
    else if (!strncmp(flechie, "Adj", 3))
        return (3);
    else if (!strncmp(flechie, "Adv", 3))
        return (4);
    return (0);
}

//put the base and the word in the tree
int ft_put_data(t_data data, t_tree *tree)
{
    int i = 0;
    //starting with the root of the right tree
    t_node *node = tree[data.arbre - 1].root;
    //put the base in the tree letter by letter
    while (data.base && data.base[i] != 0)
    {
        if (data.base[i] == '-')
        {
            if(!node ->tab_node[26])
                node ->tab_node[26] = createNode(data.base[i]);
            node = node ->tab_node[26];
        }
        else if (data.base[i] == 39)
        {
            if(!node ->tab_node[27])
                node ->tab_node[27] = createNode(data.base[i]);
            node = node ->tab_node[27];
        }
        else
        {
            if (!node ->tab_node[data.base[i] - 'a'])
                node ->tab_node[data.base[i] - 'a'] = createNode(data.base[i]);
            node = node ->tab_node[data.base[i] - 'a'];
        }
        i++;
    }
    //put the word in a list in the last letter of the base
    node ->liste_flechie = createFlechie(node ->liste_flechie, data);
    return (0);
}

int ft_read_file(t_tree *tab_tree)
{
    t_data *data = malloc(sizeof(t_data));
    FILE *fp; //FILE pointer to access a file
    char mot[30];
    char base[30];
    char flechies[100];
    char fichier[100] = "";

    printf("Enter a dictionary path\n");
    scanf("%s", fichier);
    fp = fopen(fichier, "r"); //use of the function fopen with the mode read only
    if (fp == NULL)
        return (free(data), perror("Error while opening the file\n"), errno);
    
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
    free(data);
    fclose(fp);
    printf("Trees had been generated successfully !\n");
    return (0);
}