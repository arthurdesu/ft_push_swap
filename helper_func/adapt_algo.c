#include "../push_swap.h"

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
