/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 09:58:05 by mamehri           #+#    #+#             */
/*   Updated: 2026/11/21 09:34:07 by mamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "helper/helper.h"

typedef struct s_count
{
	int		pa;
	int		pb;
	int		sa;
	int		sb;
	int		ra;
	int		rb;
	int		rrb;
	int		rra;
	float	disorder;
}	t_count;

void	chunk_sort(t_list **stack_a, t_count *count_op);
void	bubble_sort(t_list **stack_a, t_count *count_op);
void	radix_sort(t_list **stack_a, t_count *count_op);

#endif