/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 05:07:35 by nleyton           #+#    #+#             */
/*   Updated: 2022/01/29 06:42:38 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
int		is_the_list_already_sorted(t_stacks *ab);
void	indexation(t_stacks *ab);
void	duplicate_checking(t_stacks *ab);
void	init_and_parse(t_stacks *ab, int argc, char **argv);

void	parse1(t_stacks *ab, char *str);
void	parse2(t_stacks *ab, int argc, char **argv);
void	new_node(t_stacks *ab, int n);
void	check_int(char *str);

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

// sorting algorithms
void    sort(t_stacks *ab);
void    sort3(t_stacks *ab);
void    sort4n5(t_stacks *ab);
void    sort100500(t_stacks *ab, int k);
int		position(t_stacks *ab);

#endif
