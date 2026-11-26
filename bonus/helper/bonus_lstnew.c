/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_lstnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 16:08:58 by mamehri           #+#    #+#             */
/*   Updated: 2026/11/26 16:19:35 by mamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

t_ops_list	*bonus_lstnew(char *op)
{
	t_ops_list	*new;

	new = malloc(sizeof(t_ops_list));
	if (!new)
		return (NULL);
	new->op = op;
	new->next = NULL;
	return (new);
}
