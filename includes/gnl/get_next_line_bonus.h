#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
int		is_n(char *s);
char	*trim_after_zero(char *s1);
int		ft_strlen(char *s);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
#endif
