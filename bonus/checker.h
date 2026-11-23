/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 09:57:14 by mamehri           #+#    #+#             */
/*   Updated: 2026/11/21 14:31:45 by mamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "../push_swap.h"
#include "gnl/get_next_line.h"

void	rab(t_list **head);
void	rrab(t_list **head);
void	sp(t_list *node1, t_list *node2);
t_list	*psh(t_list *node, t_list **head);

#endif