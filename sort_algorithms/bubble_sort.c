/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoubtas <ymoubtas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:00:19 by mamehri           #+#    #+#             */
/*   Updated: 2026/11/21 09:45:33 by ymoubtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sort(t_list *head)
{
	while (head && head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

void	bubble_sort(t_list **stack_a, t_count *count_op)
{
	t_list	*stack_b;

	stack_b = NULL;
	while (is_sort(*stack_a) != 1)
	{
		while (*stack_a && (*stack_a)->next)
		{
			if ((*stack_a)->content > (*stack_a)->next->content)
			{
				count_op->sa++;
				ft_swap((*stack_a), (*stack_a)->next, "sa");
			}
			*stack_a = ft_push((*stack_a), &stack_b, "pb");
			count_op->pb++;
		}
		while (stack_b)
		{
			if (stack_b->next && stack_b->content < stack_b->next->content)
			{
				count_op->sb++;
				ft_swap((stack_b), stack_b->next, "sb");
			}
			stack_b = ft_push(stack_b, stack_a, "pa");
			count_op->pa++;
		}
	}
}
