#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*r;

	r = NULL;
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			r = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (r);
}
