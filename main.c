#include "push_swap.h"

int	select_flag(char	*s, t_flags *flags_list)
{
	if (ft_strncmp("--simple", s, ft_strlen(s)) == 0)
		flags_list->is_simple = 1;
	else if (ft_strncmp("--medium", s, ft_strlen(s)) == 0)
		flags_list->is_medium = 1;
	else if (ft_strncmp("--complex", s, ft_strlen(s)) == 0)
		flags_list->is_complex = 1;
	else if (ft_strncmp("--adaptive", s, ft_strlen(s)) == 0)
		flags_list->is_adaptive = 1;
	else
		return (0);
	return (1);
}

void	adapt_algo(t_list **stack_a, t_count *count_op, t_flags *flags)
{
	if (count_op->disorder < 0.2)
	{
		flags->is_simple = 1;
		bubble_sort(stack_a, count_op);
	}
	else if (count_op->disorder < 0.5)
	{
		flags->is_medium = 1;
		chunk_sort(stack_a, count_op);
	}
	else
	{
		flags->is_complex = 1;
		radix_sort(stack_a, count_op);
	}
}

int	total(t_count *count_op)
{
	int	total;

	total = count_op->pa + count_op->pb + count_op->ra
		+ count_op->rb + count_op->rrb + count_op->sa + count_op->sb;
	return (total);
}

void	call_bench(t_flags *flags_list, t_count *count_op)
{
	printf("[bench] disorder:	%f\n", count_op->disorder);
	printf("[bench] strategy:	");
	if (flags_list->is_adaptive)
		printf("adaptive / ");
	else if (flags_list->is_complex)
		printf("complex / ");
	else if (flags_list->is_medium)
		printf("medium / ");
	else if (flags_list->is_simple)
		printf("simple / ");
	if (flags_list->is_complex)
		printf("n log n\n");
	else if (flags_list->is_medium)
		printf("n√n\n");
	if (flags_list->is_simple)
		printf("n²\n");
	printf("[bench] total_ops:	%d\n", total(count_op));
	printf("[bench] sa:	%d	sb:	%d	ss:	0	pa:	%d	pb:	%d\n",
		count_op->sa, count_op->sb, count_op->pa, count_op->pb);
	printf("[bench] ra:	%d	rb:	%d	rr:	0	rra:	0	rrb:	%d\n",
		count_op->ra, count_op->rb, count_op->rrb);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_flags	flags_list;
	int		i;

	if (argc <= 1)
		return (0);
	flags_list = (t_flags){0, 0, 0, 0, 0};
	i = 1;
	if (ft_strncmp(argv[i], "--bench", ft_strlen(argv[i])) == 0)
	{
		flags_list.is_bench = 1;
		i++;
	}
	if (argv[i] && !select_flag(argv[i], &flags_list))
		flags_list.is_adaptive = 1;
	else
		i++;
	init_stack_a(&stack_a, argc - i, argv + i);
	which_sort(&stack_a, &flags_list);
	ft_lstclear(&stack_a);
}

	// radix_sort(&stack_a, &count_op); // 33136
	// chunk_sort(&stack_a, &count_op); // 52323
	// bubble_sort(&stack_a, &count_op); // 5997000