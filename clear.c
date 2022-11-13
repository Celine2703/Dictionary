#include "dictionary.h"

void	ft_clear(char **str)
{
	int	i;

	i = 0;
	while (str[i])
        free(str[i++]);
	free(str);
	str = 0;
}