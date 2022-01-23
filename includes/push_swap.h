/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 05:07:35 by nleyton           #+#    #+#             */
/*   Updated: 2022/01/23 04:00:31 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../includes/libft/libft.h"
# include <unistd.h> //write
# include <stdlib.h> //exit

typedef struct s_node{
    int value;
    int index;
    struct s_node  *next;
    struct s_node  *prev;
} t_node;

typedef struct s_stacks{
    int a_size;
    t_node *a_head;
    t_node *a_tail;
    int b_size;
    t_node *b_head;
    t_node *b_tail;
} t_stacks;




#endif
