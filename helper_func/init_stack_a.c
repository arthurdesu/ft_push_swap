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
			ft_putstr_fd("Error\n", 2);
<<<<<<< HEAD
=======
			free_all(splitted, j);
>>>>>>> moubtassim
			exit(1);
		}
		ft_lstadd_back(stack_a, node);
		j++;
	}
	free_all(splitted, j);
}

int	is_dup(t_list	*stack_a)
{
	t_list	*curr;
	t_list	*tmp;

	curr = stack_a;
	while (curr)
	{
		tmp = curr->next;
		while (tmp)
		{
			if (tmp->content == curr->content)
				return (1);
			tmp = tmp->next;
		}
		curr = curr->next;
	}
	return (0);
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
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		fill_stack_a(stack_a, splitted);
		i++;
	}
	if (is_dup(*stack_a) == 1)
	{
		ft_lstclear(stack_a);
		ft_printf("Errror\n");
		exit(1);
	}
	update_index(*stack_a);
}
