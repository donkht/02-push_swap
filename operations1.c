/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 06:15:39 by nleyton           #+#    #+#             */
/*   Updated: 2022/01/29 22:44:26 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	sa(t_stacks *ab)
{
	t_node	*tmp;

	if (ab->a_size > 1)
	{
		tmp = ab->a_head->next;
		ab->a_head->prev = tmp;
		ab->a_head->next = tmp->next;
		tmp->prev = NULL;
		tmp->next = ab->a_head;
		ab->a_head = tmp;
		write(1, "sa\n", 3);
	}
}

void	sb(t_stacks *ab)
{
	t_node	*tmp;

	if (ab->b_size > 1)
	{
		tmp = ab->b_head->next;
		ab->b_head->prev = tmp;
		ab->b_head->next = tmp->next;
		tmp->prev = NULL;
		tmp->next = ab->b_head;
		ab->b_head = tmp;
		write(1, "sb\n", 3);
	}
}

void	ss(t_stacks *ab)
{
	t_node	*tmp;

	if (ab->a_size > 1)
	{
		tmp = ab->a_head->next;
		ab->a_head->prev = tmp;
		ab->a_head->next = tmp->next;
		tmp->prev = NULL;
		tmp->next = ab->a_head;
		ab->a_head = tmp;
	}
	if (ab->b_size > 1)
	{
		tmp = ab->b_head->next;
		ab->b_head->prev = tmp;
		ab->b_head->next = tmp->next;
		tmp->prev = NULL;
		tmp->next = ab->b_head;
		ab->b_head = tmp;
	}
	write(1, "ss\n", 3);
}

void	pa(t_stacks *ab)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (ab->b_head != 0)
	{
		tmp1 = ab->b_head;
		tmp2 = ab->b_head->next;
		tmp1->next = ab->a_head;
		if (ab->a_head != NULL)
			ab->a_head->prev = tmp1;
		ab->a_head = tmp1;
		if (ab->a_tail == NULL)
			ab->a_tail = ab->a_head;
		if (tmp2 != NULL)
			tmp2->prev = NULL;
		ab->b_head = tmp2;
		ab->b_size--;
		ab->a_size++;
		write(1, "pa\n", 3);
	}
}

void	pb(t_stacks *ab)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (ab->a_head != 0)
	{
		tmp1 = ab->a_head;
		tmp2 = ab->a_head->next;
		tmp1->next = ab->b_head;
		if (ab->b_head != NULL)
			ab->b_head->prev = tmp1;
		ab->b_head = tmp1;
		if (ab->b_tail == NULL)
			ab->b_tail = ab->b_head;
		if (tmp2 != NULL)
			tmp2->prev = NULL;
		ab->a_head = tmp2;
		ab->a_size--;
		ab->b_size++;
		write(1, "pb\n", 3);
	}
}
