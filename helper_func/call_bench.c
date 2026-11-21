#include "../push_swap.h"

static int	total(t_count *count_op)
{
	int	total;

	total = count_op->pa + count_op->pb + count_op->ra
		+ count_op->rb + count_op->rrb + count_op->sa + count_op->sb + count_op->rra;
	return (total);
}

void	call_bench(t_flags *flags_list, t_count *count_op)
{
	ft_printf("[bench] disorder:	%f\n", count_op->disorder);
	ft_printf("[bench] strategy:	");
	if (flags_list->is_adaptive)
		ft_printf("adaptive / ");
	else if (flags_list->is_complex)
		ft_printf("complex / ");
	else if (flags_list->is_medium)
		ft_printf("medium / ");
	else if (flags_list->is_simple)
		ft_printf("simple / ");
	if (flags_list->is_complex)
		ft_printf("n log n\n");
	else if (flags_list->is_medium)
		ft_printf("n√n\n");
	if (flags_list->is_simple)
		ft_printf("n²\n");
	ft_printf("[bench] total_ops:	%d\n", total(count_op));
	ft_printf("[bench] sa:	%d	sb:	%d	ss:	0	pa:	%d	pb:	%d\n",
		count_op->sa, count_op->sb, count_op->pa, count_op->pb);
	ft_printf("[bench] ra:	%d	rb:	%d	rr:	0	rra:	%d	rrb:	%d	rrr:	0\n",
		count_op->ra, count_op->rb, count_op->rra, count_op->rrb);
}
