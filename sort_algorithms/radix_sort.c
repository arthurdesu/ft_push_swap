/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoubtas <ymoubtas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:00:40 by mamehri           #+#    #+#             */
/*   Updated: 2026/11/21 10:08:47 by ymoubtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	get_max_bits(int max_index)
{
	size_t	bits;

	bits = 0;
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_list **stack_a, t_count *count_op)
{
	t_list	*stack_b;
	size_t	max_bits;
	size_t	bit;
	size_t	size;

	stack_b = NULL;
	max_bits = get_max_bits(ft_lstsize(*stack_a) - 1);
	bit = 0;
	while (bit < max_bits)
	{
		size = ft_lstsize(*stack_a);
		while (size--)
		{
			if (((*stack_a)->index >> bit) & 1)
			{
				ft_r(stack_a, "ra");
				count_op->ra++;
			}
			else
			{
				count_op->pb++;
				*stack_a = ft_push(*stack_a, &stack_b, "pb");
			}
		}
		while (stack_b)
		{
			count_op->pa++;
			stack_b = ft_push(stack_b, stack_a, "pa");
		}
		bit++;
	}
}
