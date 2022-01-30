/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 05:06:04 by nleyton           #+#    #+#             */
/*   Updated: 2022/01/30 06:02:02 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	init_and_parse(t_stacks *ab, int argc, char **argv)
{
	ab->a_size = 0;
	ab->b_size = 0;
	ab->a_head = NULL;
	ab->a_tail = NULL;
	ab->b_head = NULL;
	ab->b_tail = NULL;
	if (argc == 1)
		exit_error(ab, EXIT_FAILURE);
	else if (argc == 2)
		parse1(ab, argv[1]);
	else if (argc > 2)
		parse2(ab, argc, argv);
}

void	duplicate_checking(t_stacks *ab)
{
	int		x;
	t_node	*i;
	t_node	*j;

	i = ab->a_head;
	while (i->next)
	{
		x = i->value;
		j = i;
		while (j->next)
		{
			j = j->next;
			if (x == j->value)
			{
				write(2, "Error\n", 6);
				exit_error(ab, EXIT_FAILURE);
			}	
		}
		i = i->next;
	}	
}

void	is_the_list_already_sorted(t_stacks *ab)
{
	t_node	*tmp;

	tmp = ab->a_head;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return ;
		tmp = tmp->next;
	}
	exit_error(ab, EXIT_SUCCESS);
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
		while (i->next)
		{
			i = i->next;
			if (i->value < min->value && i->index == -1)
				min = i;
		}
		min->index = current_index;
		current_index++;
	}
}

int	main(int argc, char **argv)
{
	t_stacks	ab;

	init_and_parse(&ab, argc, argv);
	duplicate_checking(&ab);
	is_the_list_already_sorted(&ab);
	indexation(&ab);
	sort(&ab);
	exit_error(&ab, EXIT_SUCCESS);
}
