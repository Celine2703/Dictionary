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

//init
t_tree	ft_init_verbe();
t_tree	createTree(t_node *node);
t_node	*createNode(char lettre);
t_list *createFlechie(t_list *list, char *str);

//parsing
int ft_choose(char *str);
int ft_remplit(char *str, t_tree tree, char *flechie);
void ft_display(t_node *node);

#endif