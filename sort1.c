/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleyton <nleyton@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 06:27:51 by nleyton           #+#    #+#             */
/*   Updated: 2022/01/27 09:16:47 by nleyton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	sort(t_stacks *ab)
{
	if (ab->a_size == 2)
		sa(ab);
	else if (ab->a_size == 3)
		sort3(ab);
	else if (ab->a_size <= 5)
		sort4n5(ab);
	else
		sort100500(ab);
}

void	sort3(t_stacks *ab)
{
	int	a;
	int b;
	int c;
	
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
void	sort100500_flag0(t_stacks *ab) //половину в Б
{
	ab->max = ab->a_size - 1;
		while (ab->a_head->flag == 0)
		{
			if (ab->a_head->index <= mid)
				pb(ab);
			else
				ra(ab);
		}
}


void	sort100500_flag1(t_stacks *ab) // все с текущим флагом в Б
{
	int	current_flag;

	current_flag = ab->a_head->flag;
	while (ab->a_head->flag == current_flag)
	{

		
	}
}

void	sort100500(t_stacks *ab)
{	
	ab->mid = ab->a_size / 2 + ab->next;

	while (!is_the_list_already_sorted(ab))
	{
		if (ab->a_head->flag == 0)
			sort100500_flag0(ab);
		if (ab->a_head->flag != 0)
			sort10500_flag1(ab);
	}

	
}
