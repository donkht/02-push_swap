#include "libft.h"
//#include <stdio.h>
//#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (len > i)
	{
		*((unsigned char *)b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}

//int	main(void)
//{
//	char s1[] = "1111111111";
//	char s2[] = "2222222222";
//
//	memset(s1,'a', 1);
//	ft_memset(s2, 'a', 7);
//	printf("memset: %s\n", s1);
//	printf("ft_memset: %s\n", s2);
//}
