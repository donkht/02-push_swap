#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n-- > 0)
	{
		*((char *)dst++) = *((char *)src++);
		if ((unsigned char)c == *(unsigned char *)(dst - 1))
			return (dst);
	}
	return (NULL);
}
