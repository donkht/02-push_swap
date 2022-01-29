/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 06:27:51 by nleyton           #+#    #+#             */
/*   Updated: 2022/01/29 05:55:29 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

// void	sort(t_stacks *ab)
// {
// 	if (ab->a_size == 2)
// 		sa(ab);
// 	else if (ab->a_size == 3)
// 		sort3(ab);
// 	else if (ab->a_size <= 5)
// 		sort4n5(ab);
// 	else
// 		do_sort_100(ab);
// 		// sort100500(ab);
// }

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
		rra(ab);
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

// //
// // void	sort100500(t_stacks *ab)
// {
// 	int	x;

// 	x = ab->a_size;
// 	ab->mid = ab->a_size / 2 + ab->next;
// 	while (x-- > 0)
// 		if (ab->a_head->index <= mid)
// 			pb(ab);
// 		else
// 			ra(ab);

// ///------------------------------------------------------------
// /// 
// 	while (ab->b_size > 0)
// 	{	

// 		//?? исправить
// 		if (ab->a_size == 2)
// 			sa(ab);
// 		else if (ab->a_size == 3)
// 			sort3(ab);
// 		else if (ab->a_size <= 5)
// 			sort4n5(ab);
// 		else 
// 		{
// 			ab->max = ab->mid;		
// 			ab->mid = (ab->max - ab->next) / 2 + ab->next;
// 			ab->flag++;
// 			x = ab->b_size;
// 			while (x-- > 0)
// 				if (ab->b_head->index >= ab->mid)
// 				{
// 					ab->b_head->flag = ab->flag;
// 					pa(ab);
// 					if (ab->a_head->index == ab->next)
// 					{
// 						ra(ab);
// 						ab->next++;
// 					}
// 					else
// 						rb(ab);
// 				}
			
// 		}
// 	}
// ///--------------------------------------------------------------
// /// переношу все элементы с текущим флагом в Б (попутно сортируя)
// 	int	current_flag = ab->a_head->flag;

// 	while (ab->a_head->flag == current_flag)
// 	{
// 		if (ab->a_head->index == ab->next)
// 		{
// 			ra(ab);
// 			ab->next++;
// 		}
// 		else
// 			pb(ab);
// 	}
// }

// void	sort100500_flag0(t_stacks *ab) //половину в Б
// {
// 	ab->max = ab->a_size - 1;
// 		while (ab->a_head->flag == 0)
// 		{
// 			if (ab->a_head->index <= mid)
// 				pb(ab);
// 			else
// 				ra(ab);
// 		}
// }
// void	sort100500_flag1(t_stacks *ab) // все с текущим флагом в Б
// {
// 	int	current_flag;

// 	current_flag = ab->a_head->flag;
// 	while (ab->a_head->flag == current_flag)
// 	{

// 	}
// }

// void	sort100500(t_stacks *ab)
// {	
// 	ab->mid = ab->a_size / 2 + ab->next;

// 	while (!is_the_list_already_sorted(ab))
// 	{
// 		if (ab->a_head->flag == 0)
// 			sort100500_flag0(ab);
// 		if (ab->a_head->flag != 0)
// 			sort10500_flag1(ab);
// 	}
// }

// int	max_i(t_stacks *ab)
// {
// 	int		i;
// 	t_node	*tmp;

// 	i = 0;
// 	tmp = ab->b_head;
// 	i = tmp->index;
// 	while (tmp != NULL)
// 	{
// 		if (i < tmp->index)
// 			i = tmp->index;
// 		tmp = tmp->next;
// 	}
// 	return (i);
// }
// int	numb_amo(t_stacks *ab)
// {
// 	t_node	*b;
// 	int		i;

// 	i = 0;
// 	b = ab->b_head;
// 	while (b->next != NULL)
// 		b = b->next, i++;
// 	return (i);
// }
// int	do_arr2(t_stacks *ab, int *num)
// {
// 	int	d;

// 	if (!(ab->b_head) || !num)
// 		return (0);
// 	d = 0;
// 	while (ab->b_head)
// 	{
// 		num[d] = ab->b_head->index;
// 		ab->b_head = ab->b_head->next;
// 		d++;
// 	}
// 	return (*num);
// }

// int	eq_src(t_stacks *ab, int med, int i)
// {
// 	int		z;
// 	int		*num;

// 	num = malloc(sizeof(int) * (i + 1));
// 	if (!num)
// 		return (0);
// 	*num = do_arr2(ab, num);
// 	z = i;
// 	while (num[i] != med)
// 		i--;
// 	z = z - i;
// 	i = 0;
// 	while (num[i] != med)
// 		i++;
// 	free(num);
// 	if (z < i)
// 		return (1);
// 	return (0);
// }

// void	do_sort_pa(t_stacks *ab)
// {
// 	while (ab->b_head != NULL)
// 	{
// 		// if (!b)
// 			// break ;
// 		if (ab->b_head->index != max_i(ab) && !eq_src(ab, max_i(ab), numb_amo(ab)))
// 			rb(ab);
// 		else if (ab->b_head->index != max_i(ab) && eq_src(ab, max_i(ab), numb_amo(ab)))
// 			rrb(ab);
// 		else if (ab->b_head->index == max_i(ab))
// 			pa(ab);
// 	}
// }

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

void	do_sort_100(t_stacks *ab)
{
	int	l;

	l = 0;
	while (ab->a_head != NULL)
	{
		if (ab->a_head->index <= l + 15)
		{
			pb(ab);
			if (ab->b_head->index <= l)
				rb(ab);
			l++;
		}
		else
			ra(ab);			
		// if (l > 1 && ab->a_head->index <= l)
		// {
		// 	pb(ab), l++;
		// 	rb(ab);
		// }
		// else if (ab->a_head->index <= l + 15)
		// 	pb(ab), l++;
		// else if (ab->a_head->index >= l)
		// 	ra(ab);
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




	
	// do_sort_pa(ab);
}

// void	do_sort_500(t_push **a, t_push **b)
// {
// 	int	l;

// 	l = 0;
// 	while ((*a) != NULL)
// 	{
// 		if (l > 1 && (*a)->index <= l)
// 		{
// 			pb(a, b), l++;
// 			rb(b);
// 		}
// 		else if ((*a)->index <= l + 30)
// 			pb(a, b), l++;
// 		else if ((*a)->index >= l)
// 			ra(a);
// 	}
// 	do_sort_pa(a, b);
// }

void	sort(t_stacks *ab)
{
	if (ab->a_size == 2)
		sa(ab);
	else if (ab->a_size == 3)
		sort3(ab);
	else if (ab->a_size <= 5)
		sort4n5(ab);
	else
		do_sort_100(ab);
		// sort100500(ab);
}