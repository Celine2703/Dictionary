#ifndef DICTIONARY_H
# define DICTIONARY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>

//struct to stock the infos of the word
typedef struct s_mot
{
	char	*temps;
	char	genre;
	char	nombre;
	char	personne;
	char	*base;
	char	*mot;
}t_mot;

typedef struct s_list
{
	int				size;
	t_mot			*mot;
	struct s_list	*next;
}t_list;

typedef struct s_node
{
	char			lettre;
	t_list			*liste_flechie;
	struct s_node	*tab_node[28];
}t_node;

typedef struct s_tree
{
	t_node	*root;
}t_tree;

typedef struct s_data
{
	char	*base;
	char	*mot;
	char	*flechie;
	int		arbre;
}	t_data;

//split
char	**ft_split(char const *str, char const c);

//init
void	ft_init_tab(t_tree *tab_tree);
void	ft_init_mot(t_mot *mot);
t_tree	createTree(t_node *node);
t_node	*createNode(char lettre);

//verif
int		ft_verif_end(t_node *node);
int		ft_leaf(t_node *node);
int		ft_empty_trees(t_tree *tab_tree);

//flechies
t_list	*createFlechie(t_list *list, t_data data);
t_mot	*createMot(t_data data);

//parsing
int		ft_choose(char *flechie);
int		ft_put_data(t_data data, t_tree *tree);
int		ft_read_file(t_tree *tab_tree);

//random
void	ft_random_word(t_tree tree);
void	ft_random_base(t_tree *tab_tree);

//sentence
void    ft_sentence_generator(t_tree *tab_tree);

//search
int		ft_base_in_tree(t_tree tree, char *str_to_search);
void	ft_base_search(t_tree *tab_tree);
char *search_in_list(t_list *liste, char *mot);
char *search_in_tree(t_node *tree, char *mot, unsigned int cpt);
void search_flechies(t_tree *tab_tree);

//display
void	ft_print_menu(void);
void	ft_display(t_node *node);
void	display_f(t_list *list);

//clear
void	ft_clear_split(char **str);
void	ft_clear_mot(t_mot *mot);
void	ft_clear_list(t_list *list);
void	ft_clear_node(t_node *node);
void	ft_clear_tree(t_tree *tree, int size);

#endif
