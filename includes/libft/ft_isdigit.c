#include "libft.h"

int	ft_isdigit(int c)
{
	if (057 < c && c < 072)
		return (1);
	else
		return (0);
}
