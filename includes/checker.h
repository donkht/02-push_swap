/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 08:59:43 by nleyton           #+#    #+#             */
/*   Updated: 2022/01/29 12:13:16 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../includes/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>


typedef struct s_node{
    int             value;
    int             index;
    struct s_node   *next;
    struct s_node   *prev;
    
} t_node;

typedef struct s_stacks{
    int            a_size;
    t_node         *a_head;
    t_node         *a_tail;
    int            b_size;
    t_node         *b_head;
    t_node         *b_tail;
} t_stacks;

// general
void	do_operations(t_stacks *ab);
void	indexation(t_stacks *ab);
void	duplicate_checking(t_stacks *ab);
void	init_and_parse(t_stacks *ab, int argc, char **argv);

void	parse1(t_stacks *ab, char *str);
void	parse2(t_stacks *ab, int argc, char **argv);
void	new_node(t_stacks *ab, int n);
void	check_int(char *str);
void		is_sorted(t_stacks *ab);

// push_swap's operations
void    sa(t_stacks *ab);
void    sb(t_stacks *ab);
void    ss(t_stacks *ab);
void	pa(t_stacks *ab);
void	pb(t_stacks *ab);

void	ra(t_stacks *ab);
void	rb(t_stacks *ab);
void	rr(t_stacks *ab);

void	rra(t_stacks *ab);
void	rrb(t_stacks *ab);
void	rrr(t_stacks *ab);

// gnl
int	get_next_line(int fd, char **line);
int	happy_end(char **remainder, char **line, char *buf);
int	add_buf_to_remainder(char **remainder, char *buf);
int	write_to_line(char **line, char **remainder, int i);

int	is_n(char *s);
char	*trim_after_zero(char *s1);
int	ft_strlen2(char *s);
int strcmp21(const char* s1, const char* s2);



# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
#endif
