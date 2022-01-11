#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;

	s2 = (unsigned char *)s;
	while (n--)
	{
		if (*s2 == (unsigned char)c)
			return (s2);
		s2++;
	}
	return (NULL);
}
