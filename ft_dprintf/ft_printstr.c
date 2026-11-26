/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 11:52:39 by mamehri           #+#    #+#             */
/*   Updated: 2026/11/26 11:52:41 by mamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_printstr(int fd, char *s)
{
	int	count;

	if (!s)
		return (ft_printstr(fd, "(null)"));
	count = 0;
	while (s[count])
	{
		if (ft_printchar(fd, s[count]) < 0)
			return (-1);
		count++;
	}
	return (count);
}
