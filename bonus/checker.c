#include "../push_swap.h"
#include "checker.h"

void	sp(t_list *node1, t_list *node2)
{
	int tmp = node1->content;
	node1->content = node2->content;
	node2->content = tmp;
}

t_list	*psh(t_list *node, t_list **head)
{
	t_list	*tmp;

	if (node == NULL)
	{
		ft_lstclear(head);
		ft_lstclear(&node);
		ft_printf("Error\n");
		exit(1);
	}
	tmp = node->next;
	node->next = *head;
	*head = node;
	return (tmp);
}

void rrab(t_list **head)
{
	t_list *curr;
	t_list *last;

	curr = *head;
	last = NULL;
	while (curr && curr->next)
	{
		if (curr->next->next == NULL)
		{
			last = curr->next;
			curr->next = NULL;
			break;
		}
		curr = curr->next;
	}
	last->next = *head;
	*head = last;
}

void rab(t_list **head)
{
	t_list *first;
	t_list	*curr;

	curr = *head;
	first = *head;
	*head = (*head)->next;
	while (curr && curr->next)
		curr = curr->next;
	curr->next = first;
	first->next = NULL;
}

void	checker(t_list **stack_a)
{
	t_list	*stack_b;
	char	*s;
	s = get_next_line(0);
	stack_b = NULL;
	while (s != NULL)
	{
		if (ft_strncmp(s, "pb", 2) == 0)
			*stack_a = psh(*stack_a, &stack_b);
		else if (ft_strncmp(s, "pa", 2) == 0)
			stack_b = psh(stack_b, stack_a);
		else if (ft_strncmp(s, "sa", 2) == 0)
			sp(*stack_a, (*stack_a)->next);
		else if (ft_strncmp(s, "sb", 2) == 0)
			sp(stack_b, stack_b->next);
		else if (ft_strncmp(s, "ra", 2) == 0)
			rab(stack_a);
		else if (ft_strncmp(s, "rb", 2) == 0)
			rab(&stack_b);
		else if (ft_strncmp(s, "rrb", 3) == 0)
			rrab(&stack_b);
		else if (ft_strncmp(s, "rra", 3) == 0)
			rrab(stack_a);
		else
		{
			ft_printf("Error\n");
			ft_lstclear(stack_a);
			ft_lstclear(&stack_b);
			exit(1);
		}
		free(s);
		s = get_next_line(0);
	}
	if (stack_b == NULL && is_sort(*stack_a) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	int		i;

	if (argc <= 1)
		return (0);
	i = 1;
	stack_a = NULL;
	ft_stack_fill(&stack_a, argc, argv, i);
	
	checker(&stack_a);
	ft_lstclear(&stack_a);
}