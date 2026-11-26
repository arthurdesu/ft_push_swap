/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 16:11:14 by mamehri           #+#    #+#             */
/*   Updated: 2026/11/26 16:18:37 by mamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static int	is_op(char *s, char *op)
{
	return (ft_strncmp(s, op, ft_strlen(s)) == 0);
}

int	ft_ops(t_list **a, t_list **b, char *s)
{
	if (is_op(s, "pb\n"))
		bonus_pb(a, b);
	else if (is_op(s, "pa\n"))
		bonus_pa(b, a);
	else if (is_op(s, "sa\n"))
		bonus_sa(*a);
	else if (is_op(s, "sb\n"))
		bonus_sb(*b);
	else if (is_op(s, "ra\n"))
		bonus_ra(a);
	else if (is_op(s, "rb\n"))
		bonus_rb(b);
	else if (is_op(s, "rra\n"))
		bonus_rra(a);
	else if (is_op(s, "rrb\n"))
		bonus_rrb(b);
	else
	{
		ft_lstclear(a);
		ft_lstclear(b);
		return (0);
	}
	return (1);
}
