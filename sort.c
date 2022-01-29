/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 06:27:51 by nleyton           #+#    #+#             */
/*   Updated: 2022/01/29 20:30:43 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	sort3(t_stacks *ab)
{
	int	a;
	int	b;
	int	c;

	a = ab->a_head->value;
	b = ab->a_head->next->value;
	c = ab->a_head->next->next->value;
	if (a > b && a < c)
		sa(ab);
	else if (a < c && b > c)
	{
		rra(ab);
		sa(ab);
	}
	else if (a < b && a > c)
		rra(ab);
	else if (a > c && b < c)
		ra(ab);
	else if (a > b && b > c)
	{
		sa(ab);
		rra(ab);
	}
}

void	sort4n5(t_stacks *ab)
{
	while (ab->a_size != 3)
		if (ab->a_head->index < ab->a_size + ab->b_size - 3)
			pb(ab);
		else
			ra(ab);
	sort3(ab);
	if (ab->b_size == 2)
		if (ab->b_head->index < ab->b_tail->index)
			sb(ab);
	while (ab->b_size > 0)
		pa(ab);
}

int	position(t_stacks *ab)
{
	int	i;
	t_node	*tmp;

	i = 1;
	tmp = ab->b_head;
	while (tmp->index != ab->b_size - 1)
	{
		i++;
		tmp = tmp->next;
	}	
	return (i);
}

void	sort100500(t_stacks *ab, int k)
{
	int	i;

	i = 0; 
	while (ab->a_head != NULL)
	{
		if (ab->a_head->index <= i + k)
		{
			pb(ab);
			if (ab->b_head->index <= i)
				rb(ab);
			i++;
		}
		else
			ra(ab);			
	}
	while (ab->b_head != NULL)
	{
		if (ab->b_head->index == ab->b_size - 1)
			pa(ab);
		else
			if (position(ab) <= ab->b_size / 2 + 1)
				rb(ab);
			else
				rrb(ab);
	}
}

void	sort(t_stacks *ab)
{
	if (ab->a_size == 2)
		sa(ab);
	else if (ab->a_size == 3)
		sort3(ab);
	else if (ab->a_size <= 5)
		sort4n5(ab);
	else if (ab->a_size <=222)
		sort100500(ab, 15);
	else
		sort100500(ab, 30);
}