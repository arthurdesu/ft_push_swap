/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 22:02:27 by mamehri           #+#    #+#             */
/*   Updated: 2026/11/21 09:36:05 by mamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

# include <stdlib.h>
# include <limits.h>

# define SIMPLE "--simple"
# define MEDIUM "--medium"
# define COMPLEX "--complex"
# define ADAPTIVE "--adaptive"
# define BENCH "--bench"

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;	
}	t_list;

typedef struct s_flags
{
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
	int	bench;
}	t_flags;

t_list			*ft_lstnew(int content);

size_t			ft_strlen(const	char *str);

char			**ft_split(char const *s, char c);

int				ft_lstclear(t_list **lst);
int				ft_putstr_fd(char *s, int fd);
int				ft_atoi(const char *nptr, int *check);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

unsigned int	ft_lstsize(t_list *lst);

void			ft_set_index(t_list *a);
void			ft_dup_nbr(t_list **stack_a);
void			ft_sort(t_list **stack_a, t_flags *flags);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_flags(int ac, char **av, t_flags *flags, int *i);
void			ft_stack_fill(t_list **stack_a, int ac, char **av, int i);

void			ft_r(t_list **head, char *s);
void			ft_rr(t_list **head, char *s);
void			ft_swap(t_list *node1, t_list *node2, char *s);
t_list			*ft_push(t_list *node, t_list **head, char *s);

#endif