/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoubtas <ymoubtas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:49:30 by mamehri           #+#    #+#             */
/*   Updated: 2026/11/23 10:17:18 by ymoubtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_r(t_list **head, char *s)
{
	t_list	*first;
	t_list	*curr;

	curr = *head;
	first = *head;
	*head = (*head)->next;
	while (curr && curr->next)
		curr = curr->next;
	curr->next = first;
	first->next = NULL;
	ft_printf(1, "%s\n", s);
}

void	ft_rr(t_list **head, char *s)
{
	t_list	*curr;
	t_list	*last;

	curr = *head;
	last = NULL;
	while (curr && curr->next)
	{
		if (curr->next->next == NULL)
		{
			last = curr->next;
			curr->next = NULL;
			break ;
		}
		curr = curr->next;
	}
	last->next = *head;
	*head = last;
	ft_printf(1, "%s\n", s);
}

void	ft_swap(t_list *node1, t_list *node2, char *s)
{
	int	tmp;

	tmp = node1->content;
	node1->content = node2->content;
	node2->content = tmp;
	ft_printf(1, "%s\n", s);
}

t_list	*ft_push(t_list *node, t_list **head, char *s)
{
	t_list	*tmp;

	tmp = node->next;
	node->next = *head;
	*head = node;
	ft_printf(1, "%s\n", s);
	return (tmp);
}
