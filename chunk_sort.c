#include "push_swap.h"

static int	sqrt_of(int n)
{
	int	i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i);
}

size_t	min_pos(t_list *list)
{
	t_list	*curr;
	int		minimum;
	size_t	pos;

	curr = list;
	minimum = curr->content;
	while (curr)
	{
		if (curr->content < minimum)
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

void	rotate_a(t_list **stack_a, t_count *count_op)
{
	size_t	size;
	size_t	min;

	size = ft_lstsize(*stack_a);
	min = min_pos(*stack_a);
	if (min <= size / 2)
	{
		while (min--)
		{
			count_op->ra++;
			r_ab(stack_a, "ra");
		}
	}
	else
	{
		min = size - min;
		while (min--)
		{
			count_op->rra++;
			rr_ab(stack_a, "rra");
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
			r_ab(stack_b, "rb");
		}
	}
	else
	{
		max = size - max;
		while (max--)
		{
			count_op->rrb++;
			rr_ab(stack_b, "rrb");
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
			*stack_a = push(*stack_a, stack_b, "pb");
			count_op->pb++;
			pushed++;
			if (pushed == limit)
				limit += (size_a / n_chunks);
		}
		else
			rotate_a(stack_a, count_op);
	}
	while (*stack_b)
	{
		rotate_b(stack_b, count_op);
		*stack_b = push(*stack_b, stack_a, "pa");
		count_op->pa++;
	}
	
}

void	chunk_sort(t_list **stack_a, t_count *count_op)
{
	t_list	*stack_b;

	stack_b = NULL;
	move_to_b(stack_a, &stack_b, count_op);
}


























































// static void	move_to_stack_b(t_list **stack_a, t_list **stack_b,
// 	t_count *count_op)
// {
// 	int		limit;
// 	int		pushed;
// 	int		size;
// 	int		chunks;

// 	size = ft_lstsize(*stack_a);
// 	chunks = sqrt_of(size);
// 	pushed = 0;
// 	limit = size / chunks;
// 	while (*stack_a)
// 	{
// 		if ((*stack_a)->index < limit)
// 		{
// 			*stack_a = push((*stack_a), stack_b, "pb");
// 			count_op->pb++;
// 			pushed++;
// 			if (pushed == limit)
// 				limit += size / chunks;
// 		}
// 		else
// 		{
// 			r_ab(stack_a, "ra");
// 			count_op->ra++;
// 		}
// 	}
// }

// static void	move_to_stack_a(t_list **stack_a, t_list **stack_b,
// 								t_count *count_op)
// {
// 	size_t	pos;
// 	size_t	size_b;

// 	while (*stack_b)
// 	{
// 		pos = max_of(*stack_b);
// 		size_b = ft_lstsize(*stack_b);
// 		if (pos < size_b - pos)
// 			while (pos-- && count_op->rb++)
// 				r_ab(stack_b, "rb");
// 		else
// 		{
// 			pos = size_b - pos;
// 			while (pos-- && count_op->rrb++)
// 				rr_ab(stack_b, "rrb");
// 		}
// 		*stack_b = push(*stack_b, stack_a, "pa");
// 		count_op->pa++;
// 	}
// }

// void	chunk_sort(t_list **stack_a, t_count *count_op)
// {
// 	t_list	*stack_b;

// 	stack_b = NULL;
// 	move_to_stack_b(stack_a, &stack_b, count_op);
// 	move_to_stack_a(stack_a, &stack_b, count_op);
// }