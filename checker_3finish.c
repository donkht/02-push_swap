/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_3finish.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 05:21:07 by nleyton           #+#    #+#             */
/*   Updated: 2022/01/30 05:21:33 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

int	do_operations_compare(t_stacks *ab, char *x)
{
	if (!strcmp21(x, "sa"))
		sa(ab);
	else if (!strcmp21(x, "sb"))
		sb(ab);
	else if (!strcmp21(x, "ss"))
		ss(ab);
	else if (!strcmp21(x, "pb"))
		pb(ab);
	else if (!strcmp21(x, "pa"))
		pa(ab);
	else if (!strcmp21(x, "ra"))
		ra(ab);
	else if (!strcmp21(x, "rb"))
		rb(ab);
	else if (!strcmp21(x, "rr"))
		rr(ab);
	else if (!strcmp21(x, "rra"))
		rra(ab);
	else if (!strcmp21(x, "rrb"))
		rrb(ab);
	else if (!strcmp21(x, "rrr"))
		rrr(ab);
	else
		return (0);
	return (1);
}

void	do_operations(t_stacks *ab)
{
	char	*x;

	while (get_next_line(0, &x))
	{
		if (do_operations_compare(ab, x))
			;
		else
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
	}
}
