//verbes
typedef struct s_tree_verbe
{
    t_node_verbe *root;
} t_tree_verbe;

typedef struct s_node_verbe
{
    char lettre;
    t_verbe *liste_flechie;
    t_node_verbe tab_node[26];
} t_node_verbe;

typedef struct s_verbe
{
    t_mot_verbe *mot;
    t_verbe *next;
} t_verbe;

typedef struct s_mot_verbe
{
    char *temps;
    char nombre;
    char personne;
    char *base;
    char *mot;
} t_mot_verbe;

//adjectifs
typedef struct s_tree_adj
{
    t_node_adj *root;
} t_tree_adj;

typedef struct s_node_adj
{
    char lettre;
    t_adj *liste_flechie;
} t_node_adj;

typedef struct s_adj
{
    t_mot_adj *mot;
    t_adj *next;
} t_adj;

typedef struct s_mot_ajd
{
    char genre;
    char nombre;
    char *base;
    char *mot;
} t_mot_adj;

//adverbes
typedef struct s_tree_adv
{
    t_node_adv *root;
} t_tree_adv;
typedef struct s_node_adv
{
    char lettre;
    t_adv *liste_flechie;
} t_node_adv;

typedef struct s_adv
{
    t_mot_adv *mot;
    t_adv *next;
} t_adv;

typedef struct s_mot_ajv
{
    char *base;
    char *mot;
} t_mot_adv;

//noms
typedef struct s_node_nom
{
    char lettre;
    t_nom *liste_flechie;
} t_node_nom;

typedef struct s_nom
{
    t_mot_nom *mot;
    t_nom *next;
} t_nom;

typedef struct s_mot_nom
{
    char genre;
    char nombre;
    char *base;
    char *mot;
} t_mot_nom;