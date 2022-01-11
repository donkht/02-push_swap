#include "libft.h"

int	ft_isalnum(int c)
{
	if ((64 < c && c < 91) || (96 < c && c < 123) || (057 < c && c < 072))
		return (42);
	else
		return (0);
}
