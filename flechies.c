#include "dictionary.h"

//create a list with the word or add the word to a existent list 
t_list *createFlechie(t_list *head, t_data data)
{
    //if there isn't a list
    if (head == NULL)
    {
        head = malloc(sizeof(t_list));
        //add the new word
        head ->mot = createMot(data);
        head ->next = NULL;
        head ->size = 1;
        return (head);
    }
    //if there is a list, add the word at the end
    else
    {
        t_list *list = head;
        while (list ->next != NULL) //go to the end of the list
            list = list ->next;
        list ->next = malloc(sizeof(t_list));
        //add the new word
        list ->next ->mot = createMot(data);
        list ->next ->next = NULL;
        head ->size += 1;
        return(head);
    }
}

//create a struct t_mot with the word
t_mot *createMot(t_data data)
{
    t_mot *mot = malloc(sizeof(t_mot));
    char **split = ft_split(data.flechie + 4, '+'); //put/split the data of the word in a table of strings
    ft_init_mot(mot);
    if (data.arbre == 1) //is it's a verb
    {
        if(split[0])
        {
            mot ->temps = strdup(split[0]); //stock the time (present, etc..)
            if(!strncmp(split[0], "PPas", 4))
            {
                if(split[1])
                {
                    mot ->genre = split[1][0]; //stock the gender info (F/M)
                    if(split[2] && split[2][0])
                        mot ->nombre = split[2][0]; //stock the info plural or singular
                }
            }
            else if(split[1])
            {
                mot ->nombre = split[1][0]; //stock the info plural or singular
                if(split[2] && split[2][0] && split[2][1])
                    mot ->personne = split[2][1]; //stock the person (first, second, third)
            }
        }
    }
    else if (data.arbre == 2 || data.arbre == 3) //is it's a noun or an adj
    {
        if(split[0])
        {
            mot ->genre = split[0][0]; //stock the genre (M/F)
            if(split[1])
                mot ->nombre = split[1][0]; //stock the info plural or singular
        }
    }
    mot ->base = strdup(data.base);
    mot ->mot = strdup(data.mot);
    ft_clear_split(split); //free the table
    return (mot);
}