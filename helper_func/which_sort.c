#include "../push_swap.h"

void	which_sort(t_list **stack_a, t_flags *flags)
{
	t_count	count_op;

	count_op = (t_count){0, 0, 0, 0, 0, 0, 0, 0, 0};
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
