#include "dictionary.h"

t_tree    ft_init_verbe()
{
    t_tree tab_verbe;
    tab_verbe = createTree(createNode(-1));
    return (tab_verbe);
}

//initializes the struct t_mot
void ft_init_mot(t_mot *mot)
{
    mot ->temps = NULL;
	mot ->genre = 0;
	mot ->nombre = 0;
	mot ->personne = 0;
	mot ->base = NULL;
	mot ->mot = NULL;
}

//create a tree
t_tree   createTree(t_node *node)
{
    t_tree tree;
    tree.root = node;
    return(tree);
}

//create a node
t_node    *createNode(char lettre)
{
    t_node *node;
    node = malloc(sizeof(t_node));
    node ->lettre = lettre;
    node ->liste_flechie = NULL;
    for(int i = 0; i < 26; i++)
        node ->tab_node[i] = NULL;
    return(node);
}

//create a list with the word or add the word to a existent list 
t_list *createFlechie(t_list *list, t_recup data)
{
    t_list *temp = list;
    //if there isn't a list yet
    if (list == NULL)
    {
        list = malloc(sizeof(t_list));
        //add the new word
        list ->mot = createMot(data);
        list ->next = NULL;
    }
    //if there is a list, add the word at the end
    else
    {
        while (list != NULL) //go to the end of the list
        {
            temp = list;
            list = list ->next;
        }
        temp ->next = malloc(sizeof(t_list));
        //add the new word
        temp ->next ->mot = createMot(data);
        temp ->next ->next = NULL;
    }
    return (list);
}

//create a struct t_mot with the word
t_mot *createMot(t_recup data)
{
    t_mot *mot = malloc(sizeof(t_mot));
    char **split = ft_split(data.flechie + 4, '+'); //put/split the data of the word in a table of strings
    ft_init_mot(mot);
    if (data.arbre == 1) //is it's a verb
    {
        if(split[0])
        {
            mot ->temps = split[0]; //stock the time (present, etc..)
            if(split[1])
            {
                mot ->nombre = split[1][0]; //stock the info plural or singular
                if(split[2] && split[2][0] && split[2][1])
                    mot ->personne = split[2][1]; //stock the person (first, second, third)
            }
        }
    }
    ft_clear_split(split); //free the table
    return (mot);
}