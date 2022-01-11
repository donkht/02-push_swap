#include "get_next_line.h"

int	is_n(char *s)
{
	if (s == NULL)
		return (0);
	while (*s != '\0')
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*trim_after_zero(char *s1)
{
	char	*s2;
	char	*copy_s1;
	int		i;

	copy_s1 = s1;
	i = 0;
	s2 = (void *)malloc(ft_strlen((char *)s1) + 1);
	if (s2 == NULL)
		return (0);
	while (i < ft_strlen((char *)s1))
	{
		*(s2 + i) = *(char *)(s1 + i);
		i++;
	}
	*(s2 + i) = 0;
	free(copy_s1);
	return (s2);
}

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*(s + len) != 0)
		len++;
	return (len);
}
