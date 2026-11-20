#include "push_swap.h"

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