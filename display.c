#include "dictionary.h"

void    ft_print_menu()
{
    printf("\nMENU :\n");
    printf("1 : Construction of trees\n");
    printf("2 : Searching for a base word\n");
    printf("3 : Searching for a flechie word\n");
    printf("4 : Generate a random base word\n");
    printf("5 : Sentence generator\n");
    printf("6 : Display of the trees\n");
    printf("0 : Exit\n\n");
}

void ft_display(t_node *node)
{
    if (node ->lettre != -1)
        printf("%c ", node ->lettre);
    if (node ->liste_flechie)
    {
        display_f(node ->liste_flechie);
    }
    for (int i = 0; i<28; i++)
    {
        if (node ->tab_node[i])
            ft_display(node ->tab_node[i]);
    }
    
}

void display_f(t_list *list)
{
    printf("\n flechies :\n");
    while (list)
    {
        printf("%s\n", list ->mot ->mot);
        list = list ->next;
    }
}