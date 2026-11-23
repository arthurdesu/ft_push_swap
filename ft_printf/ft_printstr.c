/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoubtas <ymoubtas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:11:07 by ymoubtas          #+#    #+#             */
/*   Updated: 2026/11/23 10:11:05 by ymoubtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
