#include "push_swap.h"

static t_list	*min(t_list *list)
{
	t_list	*the_min;

	the_min = list;
	while (list)
	{
		if (the_min->content > list->content && list->index == -1)
			the_min = list;
		list = list->next;
	}
	if (the_min->index != -1)
		return (NULL);
	return (the_min);
}

void	update_index(t_list *list)
{
	int		pos;
	t_list	*curr;

	pos = 0;
	while (1)
	{
		curr = min(list);
		if (curr == NULL)
			return ;
		curr->index = pos++;
	}
}

float	compute_disorder(t_list *stack_a)
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

void	init_stack_a(t_list **stack_a, int argc, char **argv)
{
	t_list	*node;
	int		i;

	i = 0;
	*stack_a = NULL;
	while (i < argc)
	{
		node = ft_lstnew(ft_atoi(argv[i]));
		if (!node)
		{
			ft_lstclear(stack_a);
			exit(1);
		}
		ft_lstadd_back(stack_a, node);
		i++;
	}
	update_index(*stack_a);
}

void	which_sort(t_list **stack_a, t_flags *flags)
{
	t_count	count_op;

	count_op = (t_count){0, 0, 0, 0, 0, 0, 0, 0};
	count_op.disorder = compute_disorder(*stack_a);
	if (flags->is_complex == 1)
		radix_sort(stack_a, &count_op);
	else if (flags->is_medium == 1)
		chunk_sort(stack_a, &count_op);
	else if (flags->is_simple == 1)
		bubble_sort(stack_a, &count_op);
	else if (flags->is_adaptive == 1)
		adapt_algo(stack_a, &count_op, flags);
	if (flags->is_bench)
		call_bench(flags, &count_op);
}
