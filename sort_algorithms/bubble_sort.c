/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:00:19 by mamehri           #+#    #+#             */
/*   Updated: 2026/11/22 14:41:03 by mamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bubble_sort(t_list **stack_a, t_list **stack_b, t_count *count_op)
{
	while (is_sort(*stack_a) != 1)
	{
		while (*stack_a && (*stack_a)->next)
		{
			if ((*stack_a)->content > (*stack_a)->next->content)
			{
				count_op->sa++;
				ft_swap((*stack_a), (*stack_a)->next, "sa");
			}
			*stack_a = ft_push((*stack_a), stack_b, "pb");
			count_op->pb++;
		}
		while (*stack_b)
		{
			if ((*stack_b)->next && (*stack_b)->content < (*stack_b)->next->content)
			{
				count_op->sb++;
				ft_swap(*stack_b, (*stack_b)->next, "sb");
			}
			*stack_b = ft_push(*stack_b, stack_a, "pa");
			count_op->pa++;
		}
	}
}
