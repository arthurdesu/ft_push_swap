/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 14:19:48 by mamehri           #+#    #+#             */
/*   Updated: 2026/11/26 14:20:53 by mamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	bonus_pb(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a == NULL)
		return ;
	push(stack_a, stack_b);
}

void	bonus_pa(t_list **stack_b, t_list **stack_a)
{
	if (*stack_b == NULL)
		return ;
	push(stack_b, stack_a);
}
