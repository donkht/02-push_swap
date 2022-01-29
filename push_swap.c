/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 05:06:04 by nleyton           #+#    #+#             */
/*   Updated: 2022/01/29 06:01:55 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	printa(t_stacks *ab)
{
	t_node	*tmp;

	tmp = ab->a_head;
	write(1, "| Stack A |\n", 12);
	while (tmp)
	{
		write(1, ft_itoa(tmp->value), ft_strlen(ft_itoa(tmp->value)));
		write(1, "\t", 1);
		write(1, ft_itoa(tmp->index), ft_strlen(ft_itoa(tmp->index)));
		write(1, "\n", 1);
		tmp = tmp->next;
	}
	write(1, "----------\n\n", 12);
}

void	printb(t_stacks *ab)
{
	t_node *tmp;
	
	tmp = ab->b_head;
	write(1, "| Stack B |\n", 12);
	while(tmp)
	{
		write(1, ft_itoa(tmp->value), ft_strlen(ft_itoa(tmp->value)));
		write(1, "\t", 1);
		write(1, ft_itoa(tmp->index), ft_strlen(ft_itoa(tmp->index)));
		write(1, "\n", 1);
		tmp = tmp->next;
	}
	write(1, "----------\n\n", 12);
}
void	new_node(t_stacks *ab, int n)
{
	t_node *tmp;

	tmp = (t_node*)malloc(sizeof(t_node));
	if (tmp == NULL)
		exit (EXIT_FAILURE);
	tmp->value = n;
	tmp->index = -1;
	// tmp->flag = 0;
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

void	check_int(char *str)
{
	int i;
	
	i = -1;
	if (ft_strlen(str) < 1)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	while (str[++i])
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
			if (!((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1])))
			{
				write(1, "Error\n", 6);
				exit(EXIT_FAILURE);
			}







			
}

void	parse1(t_stacks *ab, char *str)
{
	char **arr;
	int i;
	
	i = -1;
	arr = ft_split((char const *)str, ' ');
	while (arr[++i])
	{
		check_int(arr[i]);
		if (ft_atoi(arr[i]) == -1 && ft_strlen(arr[i]) > 2)
		{
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		new_node(ab, ft_atoi(arr[i]));
	}
	// write(1, "parse1\n", 7);
	// printa(ab);
}

void	parse2(t_stacks *ab, int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		check_int(argv[i]);
		if (ft_atoi(argv[i]) == -1 && ft_strlen(argv[i]) > 2)
		{
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}	
		new_node(ab, ft_atoi(argv[i++]));
	}
	// write(1, "parse2 finished\n", 16);
	// printa(ab);   //delete
	

}

void	init_and_parse(t_stacks *ab, int argc, char **argv)
{
	ab->a_size = 0;
	ab->b_size = 0;
	ab->a_head = NULL;
	ab->a_tail = NULL;
	ab->b_head = NULL;
	ab->b_tail = NULL;
	// ab->flag = 0;
	// ab->mid = 0;
	// ab->next = 0;
	// ab->max = -1;
	if (argc == 1)
		exit(EXIT_FAILURE);
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
				write(1, "Error\n", 6);
				exit(EXIT_FAILURE);
			}	
		}
		i = i->next;
	}	
}

int		is_the_list_already_sorted(t_stacks *ab)
{
	t_node *tmp;

	tmp = ab->a_head;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	exit(EXIT_FAILURE);
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
	// printa(ab);   //delete
}






int main (int argc, char **argv)
{
	t_stacks	ab;

	init_and_parse(&ab, argc, argv);
	duplicate_checking(&ab);
	is_the_list_already_sorted(&ab);
	indexation(&ab);

	// write(1, "after operations:\n", 18);
	// pb(&ab);
	// pb(&ab);
	// pb(&ab);
	// printa(&ab); 
	// printb(&ab); 
	// write(1, "after operations:\n", 18);
	// rra(&ab);
	// rrb(&ab);
	// rb(&ab);
	// printa(&ab); 
	// printb(&ab); 
	
	sort(&ab); 

	// printa(&ab);
	// clear 
	exit(EXIT_SUCCESS);
}