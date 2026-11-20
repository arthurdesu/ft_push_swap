#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

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

typedef struct s_flags
{
	int	is_adaptive;
	int	is_simple;
	int	is_medium;
	int	is_complex;
	int	is_bench;
}	t_flags;

int				is_sort(t_list *head);

void			swap(t_list *node1, t_list *node2, char *s);
t_list			*push(t_list *node, t_list **head, char *s);
void			r_ab(t_list **head, char *s);
void			rr_ab(t_list **head, char *s);

void			bubble_sort(t_list **stack_a, t_count *count_op);
void			chunk_sort(t_list **stack_a, t_count *count_op);
void			radix_sort(t_list **stack_a, t_count *count_op);

float			compute_disorder(t_list *stack_a);
void			update_index(t_list *list);

void			which_sort(t_list **stack_a, t_flags *flags);
void			init_stack_a(t_list **stack_a, int argc, char **argv);
void			adapt_algo(t_list **stack_a, t_count *count_op, t_flags *flags);
void			call_bench(t_flags *flags_list, t_count *count_op);

char			**ft_split(char const *s, char c);
void			ft_lstclear(t_list **lst);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_lstadd_back(t_list **lst, t_list *new);
int				select_flag(char *s, t_flags *flags_list);
size_t			ft_strlen(const	char *str);
int				ft_atoi(const char *nptr);
t_list			*ft_lstnew(int content);
unsigned int	ft_lstsize(t_list *lst);
void			ft_putstr_fd(char *s, int fd);

#endif