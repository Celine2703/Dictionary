#include "dictionary.h"

//base
 
// look if str_to_search is a base word of tree
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

// get the input and start the research on the selected tree
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

//flechie
// look if mot is contained on a t_list 
char *search_in_list(t_list *liste, char *mot)
{
	while (liste)
	{
		if (strcmp(liste->mot->mot, mot) == 0)
			return (liste->mot->mot);
		liste = liste->next;
	}
	return (NULL);
}
// look if a mot is contained on a tree
char *search_in_tree(t_node *tree, char *mot, unsigned int cpt)
{
	char *result = NULL;
	(void)cpt;
	if (tree == NULL)
		return (NULL);
	result = search_in_list(tree->liste_flechie, mot); //look if it is on this node
	if (result)
		return (result);
	if(strlen(mot) > cpt) // if mot is not ended go to the next corresponding node
	{
		if (mot[cpt + 1] == '-')
			result = search_in_tree(tree->tab_node[26], mot, cpt + 1);
		else if (mot[cpt + 1] == '\'')
			result = search_in_tree(tree->tab_node[27], mot, cpt + 1);
		else if (tree->tab_node[mot[cpt] - 'a'])
			result = search_in_tree(tree->tab_node[mot[cpt] - 'a'], mot, cpt + 1);
	}
	if (result)
		return (result);
	for (int i = 0; i < 28; i++) // go look on another child node
	{
		result = search_in_tree(tree->tab_node[i], mot,cpt +1);
		if (result)
			return (result);
	}
	return (NULL);
}

//take the input and launch a flechie search and print the result
void search_flechies(t_tree *tab_tree)
{
    char *result = NULL;
    char flechie_word[30];
	char classe[10];

    printf("Which flechie? ");
    scanf("\n%s", flechie_word);
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
			result = search_in_tree(tab_tree[i].root, flechie_word, 0);
			if (result)
			{
				printf("The word %s has been found !\n", result);
				return;
			}
		}
		printf("The %s hasn't been found\n", result);
    }
    else
    {
        result = search_in_tree(tab_tree[ft_choose(classe) - 1].root, flechie_word, 0);
		if (result)
            printf("The word %s has been found !\n", result);
        else
            printf("The word %s hasn't been found !\n", result);
    }
}