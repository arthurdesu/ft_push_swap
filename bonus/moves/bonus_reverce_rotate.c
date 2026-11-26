/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_reverce_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 14:23:22 by mamehri           #+#    #+#             */
/*   Updated: 2026/11/26 14:36:04 by mamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	bonus_rra(t_list **stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	reverse_rotate(stack_a);
}

void	bonus_rrb(t_list **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	reverse_rotate(stack_b);
}
