/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 06:33:44 by nleyton           #+#    #+#             */
/*   Updated: 2022/01/30 06:29:48 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	new_node(t_stacks *ab, int n)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (tmp == NULL)
		exit_error(ab, EXIT_FAILURE);
	tmp->value = n;
	tmp->index = -1;
	if (ab->a_head == NULL)
	{
		ab->a_head = tmp;
		ab->a_tail = tmp;
		tmp->prev = NULL;
		tmp->next = NULL;
	}
	else
	{
		ab->a_tail->next = tmp;
		tmp->prev = ab->a_tail;
		tmp->next = NULL;
		ab->a_tail = tmp;
	}
	ab->a_size++;
}

void	check_int(t_stacks *ab, char *str)
{
	int	i;

	i = -1;
	if (ft_strlen(str) < 1)
	{
		write(2, "Error\n", 6);
		exit_error(ab, EXIT_FAILURE);
	}
	while (str[++i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
		{
			if (!((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1])))
			{
				write(2, "Error\n", 6);
				exit_error(ab, EXIT_FAILURE);
			}
		}
	}
}

void	parse1(t_stacks *ab, char *str)
{
	char	**arr;
	int		i;

	i = -1;
	arr = ft_split((char const *)str, ' ');
	while (arr[++i])
	{
		check_int(ab, arr[i]);
		if (ft_atoi(arr[i]) == -1 && ft_strlen(arr[i]) > 2)
		{
			write(2, "Error\n", 6);
			exit_error(ab, EXIT_FAILURE);
		}
		new_node(ab, ft_atoi(arr[i]));
	}
}

void	parse2(t_stacks *ab, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		check_int(ab, argv[i]);
		if (ft_atoi(argv[i]) == -1 && ft_strlen(argv[i]) > 2)
		{
			write(2, "Error\n", 6);
			exit_error(ab, EXIT_FAILURE);
		}	
		new_node(ab, ft_atoi(argv[i++]));
	}
}

void	exit_error(t_stacks *ab, int x)
{
	t_node	*tmp;

	tmp = NULL;
	while (ab->a_head)
	{
		tmp = ab->a_head->next;
		free(ab->a_head);
		ab->a_head = tmp;
	}
	while (ab->b_head)
	{
		tmp = ab->b_head->next;
		free(ab->b_head);
		ab->b_head = tmp;
	}
	exit(x);
}
