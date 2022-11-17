#include "dictionary.h"

int main(int argc, char **argv)
{
    (void)argv;
    if (argc >= 2) //the program should be executed without arguments
        return (0);
    int input;
    
    t_tree tab_tree[4];

    ft_print_menu();
    ft_init_tab(tab_tree);
    //menu
    do{
    scanf("%i", &input);
    
    if (input == 1){
    ft_read_file(tab_tree);
    ft_print_menu();
    }
    else if (input == 2){
    
    //diplay the trees
    ft_display(tab_tree[0].root);
    printf("\n");
    ft_display(tab_tree[1].root);
    printf("\n");
    ft_display(tab_tree[2].root);
    printf("\n");
    ft_display(tab_tree[3].root);
    ft_print_menu();
    }

    else if(input == 3){
    //random base word
    ft_random_base(tab_tree);
    ft_print_menu();
    }

    else if (input == 4){
    //search
    ft_base_search(tab_tree);
    ft_print_menu();
    }

    } while(input != 6);
    //clear
    ft_clear_tree(tab_tree, 4);
    return (0);
}