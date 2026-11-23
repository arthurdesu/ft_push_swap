/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 21:17:47 by mamehri           #+#    #+#             */
/*   Updated: 2026/11/22 14:39:18 by mamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_total(t_count *c)
{
	return (c->pa + c->pb + c->ra + c->rb + c->rrb + c->sa + c->sb + c->rra);
}

static void	ft_bench(t_flags *flags_list, t_count *count_op)
{
	ft_printf("[bench] disorder:	%f\n", count_op->disorder);
	ft_printf("[bench] strategy:	");
	if (flags_list->adaptive)
		ft_printf("Adaptive / ");
	else if (flags_list->simple)
		ft_printf("Simple / ");
	else if (flags_list->medium)
		ft_printf("Medium / ");
	else if (flags_list->complex)
		ft_printf("Complex / ");
	else
		ft_printf("Adaptive / ");
	if (flags_list->simple)
		ft_printf("O(n²)\n");
	else if (flags_list->medium)
		ft_printf("O(n√n)\n");
	else if (flags_list->complex)
		ft_printf("O(n log n)\n");
	ft_printf("[bench] total_ops:	%d\n", ft_total(count_op));
	ft_printf("[bench] sa:	%d	sb:	%d	ss:	0	pa:	%d	pb:	%d\n",
		count_op->sa, count_op->sb, count_op->pa, count_op->pb);
	ft_printf("[bench] ra:	%d	rb:	%d	rr:	0	rra:	%d	rrb:	%d	rrr:	0\n",
		count_op->ra, count_op->rb, count_op->rra, count_op->rrb);
}

static float	ft_disorder(t_list *stack_a)
{
	t_list	*curr;
	int		mistakes;
	int		total_pairs;

	mistakes = 0;
	total_pairs = 0;
	while (stack_a)
	{
		curr = stack_a->next;
		while (curr)
		{
			total_pairs += 1;
			if (stack_a->content > curr->content)
				mistakes++;
			curr = curr->next;
		}
		stack_a = stack_a->next;
	}
	return ((float)mistakes / total_pairs);
}

static void	adapt_algo(t_list **stack_a, t_list **stack_b, t_count *count_op, t_flags *flags)
{
	if (count_op->disorder < 0.2)
	{
		flags->simple = 1;
		bubble_sort(stack_a, stack_b, count_op);
	}
	else if (count_op->disorder < 0.5)
	{
		flags->medium = 1;
		chunk_sort(stack_a, count_op);
	}
	else
	{
		flags->complex = 1;
		radix_sort(stack_a, count_op);
	}
}

void	ft_sort(t_list **stack_a, t_flags *flags)
{
	t_count	count_op;
	t_list	*stack_b;

	stack_b = NULL;
	count_op = (t_count){0};
	count_op.disorder = ft_disorder(*stack_a);
	if (flags->simple)
		bubble_sort(stack_a, &stack_b, &count_op);
	else if (flags->medium)
		chunk_sort(stack_a, &count_op);
	else if (flags->complex)
		radix_sort(stack_a, &count_op);
	else
		adapt_algo(stack_a, &stack_b, &count_op, flags);
	if (flags->bench)
		ft_bench(flags, &count_op);
}
