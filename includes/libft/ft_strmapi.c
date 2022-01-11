#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	i;

	if (!s)
		return (NULL);
	ret = malloc(ft_strlen(s) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		ret[i] = f((unsigned int)i, s[i]);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
