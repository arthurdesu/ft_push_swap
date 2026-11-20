#include "../push_swap.h"

static int	total(t_count *count_op)
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
