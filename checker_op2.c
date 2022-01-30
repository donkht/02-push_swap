/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 06:04:36 by nleyton           #+#    #+#             */
/*   Updated: 2022/01/29 22:56:13 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

void	ra(t_stacks *ab)
{
	t_node	*tmp;

	if (ab->a_size > 1)
	{
		tmp = ab->a_head;
		ab->a_tail->next = tmp;
		tmp->prev = ab->a_tail;
		ab->a_tail = tmp;
		tmp->next->prev = NULL;
		ab->a_head = tmp->next;
		tmp->next = NULL;
	}
}

void	rb(t_stacks *ab)
{
	t_node	*tmp;

	if (ab->b_size > 1)
	{
		tmp = ab->b_head;
		ab->b_tail->next = tmp;
		tmp->prev = ab->b_tail;
		ab->b_tail = tmp;
		tmp->next->prev = NULL;
		ab->b_head = tmp->next;
		tmp->next = NULL;
	}
}

void	rr(t_stacks *ab)
{
	t_node	*tmp;

	if (ab->a_size > 1)
	{
		tmp = ab->a_head;
		ab->a_tail->next = tmp;
		tmp->prev = ab->a_tail;
		ab->a_tail = tmp;
		tmp->next->prev = NULL;
		ab->a_head = tmp->next;
		tmp->next = NULL;
	}
	if (ab->a_size > 1)
	{
		tmp = ab->b_head;
		ab->b_tail->next = tmp;
		tmp->prev = ab->b_tail;
		ab->b_tail = tmp;
		tmp->next->prev = NULL;
		ab->b_head = tmp->next;
		tmp->next = NULL;
	}
}
