#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	if (dstsize < 1)
		return (ft_strlen((char *)src));
	while (i < dstsize - 1)
	{
		dst[i] = src[i];
		if (src[i] == 0)
			return (ft_strlen((char *)src));
		i++;
	}
	dst[i] = 0;
	return (ft_strlen((char *)src));
}
