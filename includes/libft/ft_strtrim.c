#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	len;

	if (!s1)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1 != 0)
		s1++;
	len = ft_strlen((char *)s1);
	while (ft_strchr(set, *(s1 + len - 1)) && len > 1)
		len--;
	ret = ft_substr(s1, 0, len);
	return (ret);
}
