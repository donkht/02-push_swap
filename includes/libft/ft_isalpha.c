#include "libft.h"

int	ft_isalpha(int c)
{
	unsigned char	a;

	a = (unsigned char)c;
	if ((64 < c && c < 91) || (96 < c && c < 123))
		return (42);
	else
		return (0);
}
