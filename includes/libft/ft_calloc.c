#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*p;

	p = malloc(count * size);
	if (p == NULL)
		return (0);
	ft_bzero(p, count * size);
	return (p);
}
