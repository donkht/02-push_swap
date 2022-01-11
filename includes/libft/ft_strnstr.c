#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	if (*haystack == 0)
		return (NULL);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j])
			j++;
		if (!needle[j] && i + j <= len)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
