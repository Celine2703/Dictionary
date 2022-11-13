#ifndef DICTIONARY_H
# define DICTIONARY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_mot
{
	char *temps;
	char genre;
	char nombre;
	char personne;
	char *base;
	char *mot;
} t_mot;

typedef struct s_list
{
	t_mot *mot;
	struct s_list *next;
} t_list;

typedef struct s_node
{
	char lettre;
	t_list *liste_flechie;
	struct s_node *tab_node[26];
} t_node;

typedef struct s_tree
{
	t_node *root;
} t_tree;

typedef struct s_recup
{
	char *base;
	char *mot;
	char *flechie;
	int arbre;
}	t_recup;

//split
char	**ft_split(char const *str, char const c);

//init
t_tree	ft_init_verbe();
t_tree	createTree(t_node *node);
t_node	*createNode(char lettre);
t_list *createFlechie(t_list *list, t_recup data);
t_mot *createMot(t_recup data);

//parsing
int ft_choose(char *flechie);
int ft_remplit(t_recup data, t_tree tree);
void ft_display(t_node *node);

//clear
void	ft_clear_split(char **str);

#endif

/*a faire :
parsing verif mot a traiter
split a clean
*/