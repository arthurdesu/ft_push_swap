/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 09:57:14 by mamehri           #+#    #+#             */
/*   Updated: 2026/11/26 16:13:25 by mamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"
# include "gnl/get_next_line.h"

typedef struct s_ops_list
{
	void				*op;
	struct s_ops_list	*next;
}	t_ops_list;

void		bonus_pa(t_list **b, t_list **a);
void		bonus_pb(t_list **a, t_list **b);

void		bonus_rra(t_list **a);
void		bonus_rrb(t_list **b);

void		bonus_ra(t_list **a);
void		bonus_rb(t_list **b);

void		bonus_sa(t_list *a);
void		bonus_sb(t_list *b);

t_ops_list	*bonus_lstnew(char *op);

int			ft_ops(t_list **a, t_list **b, char *s);

void		bonus_lstclear(t_ops_list **lst);
void		bonus_lstadd_back(t_ops_list **lst, t_ops_list *new);

#endif