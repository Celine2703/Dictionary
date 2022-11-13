#ifndef DICTIONARY_H
# define DICTIONARY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//struct to stock the infos of the word
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
void    ft_init_tab(t_tree *tab_tree);
t_tree	createTree(t_node *node);
t_node	*createNode(char lettre);
t_list *createFlechie(t_list *list, t_recup data);
t_mot *createMot(t_recup data);

//parsing
int ft_choose(char *flechie);
int ft_remplit(t_recup data, t_tree *tree);
void ft_display(t_node *node);

//clear
void	ft_clear_split(char **str);

#endif

/*a faire :
parsing verif mot a traiter (et ceux a pas traiter dc)
Définir une structure de données adaptée au stockage des formes fléchies. Cette 
structure devra comporter un entier indiquant le nombre de formes fléchies qu’elle 
stocke ; 
Justifier ce choix dans votre rapport de projet ; 
Dans les nœuds adaptés à cette catégorie, stocker un pointeur vers cette structure de 
données, et non directement cette structure de données. Vous indiquerez également 
dans votre rapport, pourquoi cette contrainte est réellement utile et nécessaire pour 
l’implémentation du programme.

stocker l infinitif des verbs

Formes fléchies manquantes 
Il se peut que certaines formes fléchies soient manquantes : dans ce cas, il vous faut 
trouver un moyen de noter cette information de manière claire

4 5
*/