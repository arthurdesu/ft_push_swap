/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 14:22:37 by mamehri           #+#    #+#             */
/*   Updated: 2026/11/26 14:36:13 by mamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	bonus_ra(t_list **stack_a)
{
	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	rotate(stack_a);
}

void	bonus_rb(t_list **stack_b)
{
	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	rotate(stack_b);
}
