/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 05:06:04 by nleyton           #+#    #+#             */
/*   Updated: 2022/01/29 21:13:06 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

void	do_operations(t_stacks *ab)
{
	char *x;
	
	// x = NULL;
	while (get_next_line(0, &x))
	{
		write(1, "|", 1);
		write(1, x, ft_strlen(x));
		write(1, "|\n", 2);
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
			write(2, "Error\n", 6), exit(EXIT_FAILURE);
	}
}

void	init_and_parse(t_stacks *ab, int argc, char **argv)
{
	ab->a_size = 0;
	ab->b_size = 0;
	ab->a_head = NULL;
	ab->a_tail = NULL;
	ab->b_head = NULL;
	ab->b_tail = NULL;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	else if (argc == 2)
		parse1(ab, argv[1]);
	else if (argc > 2)
		parse2(ab, argc, argv);
}

void	duplicate_checking(t_stacks *ab)
{
	int	x;
	t_node *i;
	t_node *j;
	
	i = ab->a_head;
	while (i->next)
	{
		x = i->value;
		j = i;
		while(j->next)
		{
			j = j->next;
			if (x == j->value)
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}	
		}
		i = i->next;
	}	
}

void	indexation(t_stacks *ab)
{
	t_node	*i;
	t_node	*min;
	int		current_index;

	current_index = 0;
	while (current_index < ab->a_size)
	{
		i = ab->a_head;
		while (i->index != -1)
			i = i->next;
		min = i;
		while(i->next)
		{
			i = i->next;
			if (i->value < min->value && i->index == -1)
				min = i;
		}
		min->index = current_index;
		current_index++;
	}
}

int main(int argc, char **argv)
{
	t_stacks	ab;

	init_and_parse(&ab, argc, argv);
	duplicate_checking(&ab);
	indexation(&ab);
	do_operations(&ab);
	is_sorted(&ab);
	exit(EXIT_SUCCESS);
}