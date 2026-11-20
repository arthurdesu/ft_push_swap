#include "../push_swap.h"

static void	free_all(char **splitted, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

static void	fill_stack_a(t_list **stack_a, char **splitted)
{
	t_list	*node;
	int		j;

	j = 0;
	while (splitted[j] != NULL)
	{
		node = ft_lstnew(ft_atoi(splitted[j]));
		if (!node)
		{
			ft_lstclear(stack_a);
			exit(1);
		}
		ft_lstadd_back(stack_a, node);
		j++;
	}
	free_all(splitted, j);
}

void	init_stack_a(t_list **stack_a, int argc, char **argv)
{
	int		i;
	char	**splitted;

	i = 0;
	*stack_a = NULL;
	while (i < argc)
	{
		splitted = ft_split(argv[i], ' ');
		if (splitted == NULL)
		{
			ft_lstclear(stack_a);
			exit(1);
		}
		fill_stack_a(stack_a, splitted);
		i++;
	}
	update_index(*stack_a);
}
