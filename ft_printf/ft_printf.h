/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoubtas <ymoubtas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:10:56 by ymoubtas          #+#    #+#             */
/*   Updated: 2026/11/23 10:11:22 by ymoubtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(int fd, const char *f, ...);
int	ft_printchar(int fd, int c);
int	ft_printnbr_base(int fd, long n, char *srcbase);
int	ft_printstr(int fd, char *s);
int	ft_printaddress(int fd, void *p);

#endif