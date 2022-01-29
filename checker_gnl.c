/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 09:51:04 by nleyton           #+#    #+#             */
/*   Updated: 2022/01/29 11:07:11 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

int	write_to_line(char **line, char **remainder, int i)
{
	int		n;
	char	*new_remainder;

	n = 0;
	i = 0;
	while (remainder[0][n] != '\n')
		n++;
	*line = (char *)malloc(n + 1);
	if (*line == NULL)
		return (-1);
	line[0][n] = 0;
	while (remainder[0][i] != '\0')
		i++;
	new_remainder = (char *)malloc(i - n);
	if (new_remainder == NULL)
		return (-1);
	new_remainder[i - n - 1] = 0;
	i = -1;
	while (++i < n)
		line[0][i] = remainder[0][i];
	while (remainder[0][++i] != '\0')
		new_remainder[i - n - 1] = remainder[0][i];
	free(*remainder);
	*remainder = new_remainder;
	return (1);
}

int	add_buf_to_remainder(char **remainder, char *buf)
{
	char	*new_remainder;
	int		x;
	int		i;

	if (*remainder == NULL)
	{
		*remainder = buf;
		return (21);
	}
	new_remainder = (char *)malloc (ft_strlen2(*remainder) + ft_strlen2(buf) + 1);
	if (new_remainder == NULL)
		return (0);
	new_remainder[ft_strlen2(*remainder) + ft_strlen2(buf)] = '\0';
	x = 0;
	i = 0;
	while (remainder[0][x] != '\0')
		new_remainder[i++] = remainder[0][x++];
	x = 0;
	while (buf[x] != '\0')
		new_remainder[i++] = buf[x++];
	free((void *)*remainder);
	*remainder = new_remainder;
	free(buf);
	return (21);
}

int	happy_end(char **remainder, char **line, char *buf)
{
	if (*remainder == NULL)
	{
		*line = (void *)malloc(1);
		if (*line == NULL)
		{
			free(buf);
			return (-1);
		}
		line[0][0] = 0;
		free(buf);
		return (0);
	}
	*line = *remainder;
	*remainder = NULL;
	free(buf);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*remainder;
	char		*buf;
	int			i;

	i = 0;
	if (is_n(remainder))
		return (write_to_line(line, &remainder, i));
	while (!(is_n(remainder)))
	{
		buf = (char *)malloc(BUFFER_SIZE + 1);
		buf[BUFFER_SIZE] = 0;
		i = read(fd, buf, BUFFER_SIZE);
		if (buf == NULL || i < 0 || fd < 0 || BUFFER_SIZE <= 0)
		{
			free(buf);
			return (-1);
		}
		buf[i] = 0;
		buf = trim_after_zero(buf);
		if (!i)
			return (happy_end(&remainder, line, buf));
		if (!add_buf_to_remainder(&remainder, buf))
			return (-1);
	}
	return (write_to_line(line, &remainder, i));
}