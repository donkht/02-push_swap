/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 06:03:43 by nleyton           #+#    #+#             */
/*   Updated: 2022/01/29 22:56:35 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

void	rra(t_stacks *ab)
{
	t_node	*tmp;

	if (ab->a_size > 1)
	{
		tmp = ab->a_tail;
		ab->a_head->prev = tmp;
		tmp->next = ab->a_head;
		ab->a_head = tmp;
		tmp->prev->next = NULL;
		ab->a_tail = tmp->prev;
		tmp->prev = NULL;
	}
}

void	rrb(t_stacks *ab)
{
	t_node	*tmp;

	if (ab->b_size > 1)
	{
		tmp = ab->b_tail;
		ab->b_head->prev = tmp;
		tmp->next = ab->b_head;
		ab->b_head = tmp;
		tmp->prev->next = NULL;
		ab->b_tail = tmp->prev;
		tmp->prev = NULL;
	}
}

void	rrr(t_stacks *ab)
{
	t_node	*tmp;

	if (ab->a_size > 1)
	{
		tmp = ab->a_tail;
		ab->a_head->prev = tmp;
		tmp->next = ab->a_head;
		ab->a_head = tmp;
		tmp->prev->next = NULL;
		ab->a_tail = tmp->prev;
		tmp->prev = NULL;
	}
	if (ab->b_size > 1)
	{
		tmp = ab->b_tail;
		ab->b_head->prev = tmp;
		tmp->next = ab->b_head;
		ab->b_head = tmp;
		tmp->prev->next = NULL;
		ab->b_tail = tmp->prev;
		tmp->prev = NULL;
	}
}
