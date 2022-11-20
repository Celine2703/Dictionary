#include "dictionary.h"

int main(int argc, char **argv)
{
    (void)argv;
    if (argc >= 2) //the program should be executed without arguments
        return (0);
    
    char input;
    t_tree tab_tree[4];

    ft_print_menu();
    ft_init_tab(tab_tree);
    srand((unsigned)time(NULL));
    //menu
    do{
        scanf("%c", &input);
        scanf("%*[^\n]");
        getchar();

        if (input == '1'){
        ft_read_file(tab_tree);
        ft_print_menu();
        }

        else if (input == '2'){
        //search base form
        ft_base_search(tab_tree);
        ft_print_menu();
        }

        else if(input == '3'){
        //search flechie form
        search_flechies(tab_tree);
        ft_print_menu();
        }

        else if(input == '4'){
        //random base word
        ft_random_base(tab_tree);
        ft_print_menu();
        }
        
        else if (input == '5'){
        //sentence generator
        ft_sentence_generator(tab_tree);
        ft_print_menu();
        }

        else if (input == '6'){
        
        //diplay the trees
        printf("Optional request\n\n");
        ft_display(tab_tree[0].root);
        printf("\n");
        ft_display(tab_tree[1].root);
        printf("\n");
        ft_display(tab_tree[2].root);
        printf("\n");
        ft_display(tab_tree[3].root);
        ft_print_menu();
        }

        else if (input == '0')
            printf("EXIT\n");

        else
            printf("Incorrect input. Please try again.\n");

    } while(input != '0');
    //clear
    ft_clear_tree(tab_tree, 4);
    return (0);
}