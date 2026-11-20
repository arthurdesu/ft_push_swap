#include "../push_swap.h"

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
