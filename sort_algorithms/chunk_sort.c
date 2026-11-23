/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoubtas <ymoubtas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:00:29 by mamehri           #+#    #+#             */
/*   Updated: 2026/11/23 10:26:37 by ymoubtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	sqrt_of(long n)
{
	long	i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i);
}

size_t	min_pos(t_list *list, int limit)
{
	t_list	*curr;
	int		minimum;
	size_t	pos;

	curr = list;
	while (curr)
	{
		if (curr->index < limit)
			minimum = curr->content;
		curr = curr->next;
	}
	pos = 0;
	while (list && list->content != minimum)
	{
		pos++;
		list = list->next;
	}
	return (pos);
}

void	rotate_a(t_list **stack_a, t_count *count_op, int limit)
{
	size_t	size;
	size_t	min;

	size = ft_lstsize(*stack_a);
	min = min_pos(*stack_a, limit);
	if (min <= size / 2)
	{
		while (min--)
		{
			count_op->ra++;
			ft_r(stack_a, "ra");
		}
	}
	else
	{
		min = size - min;
		while (min--)
		{
			count_op->rra++;
			ft_rr(stack_a, "rra");
		}
	}
}

static int	max_pos(t_list *list)
{
	t_list	*curr;
	int		value;
	int		pos;

	curr = list;
	value = list->content;
	while (curr)
	{
		if (curr->content > value)
			value = curr->content;
		curr = curr->next;
	}
	pos = 0;
	while (list && list->content != value)
	{
		pos++;
		list = list->next;
	}
	return (pos);
}

void	rotate_b(t_list **stack_b, t_count *count_op)
{
	size_t	size;
	size_t	max;

	size = ft_lstsize(*stack_b);
	max = max_pos(*stack_b);
	if (max <= size / 2)
	{
		while (max--)
		{
			count_op->rb++;
			ft_r(stack_b, "rb");
		}
	}
	else
	{
		max = size - max;
		while (max--)
		{
			count_op->rrb++;
			ft_rr(stack_b, "rrb");
		}
	}
}

void	move_to_b(t_list **stack_a, t_list **stack_b, t_count *count_op)
{
	int	n_chunks;
	int	size_a;
	int	limit;
	int	pushed;

	size_a = ft_lstsize(*stack_a);
	n_chunks = sqrt_of(size_a);
	limit = size_a / n_chunks;
	pushed = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index < limit)
		{
			*stack_a = ft_push(*stack_a, stack_b, "pb");
			count_op->pb++;
			pushed++;
			if (pushed == limit)
				limit += (size_a / n_chunks);
		}
		else
			rotate_a(stack_a, count_op, limit);
	}
	while (*stack_b)
	{
		rotate_b(stack_b, count_op);
		*stack_b = ft_push(*stack_b, stack_a, "pa");
		count_op->pa++;
	}
}

void	chunk_sort(t_list **stack_a, t_count *count_op)
{
	t_list	*stack_b;

	stack_b = NULL;
	move_to_b(stack_a, &stack_b, count_op);
}
