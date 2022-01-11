#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	ret;
	int	sign;

	i = 0;
	ret = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + str[i] - 48;
		i++;
	}
	return (ret * sign);
}
