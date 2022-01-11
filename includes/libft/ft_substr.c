#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen((char *)s) || len == 0)
		return (ft_strdup(""));
	if (ft_strlen((char *)(s + start)) < len)
		len = ft_strlen((char *)(s + start));
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		*(str + i) = *(s + start + i);
	str[i] = 0;
	return (str);
}
