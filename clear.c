#include "dictionary.h"

//clear a table of strings
void	ft_clear_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
        free(str[i++]);
	free(str);
	str = 0;
}