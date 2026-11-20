#include "../push_swap.h"

int	select_flag(char *s, t_flags *flags_list)
{
	if (ft_strncmp("--simple", s, ft_strlen(s)) == 0)
		flags_list->is_simple = 1;
	else if (ft_strncmp("--medium", s, ft_strlen(s)) == 0)
		flags_list->is_medium = 1;
	else if (ft_strncmp("--complex", s, ft_strlen(s)) == 0)
		flags_list->is_complex = 1;
	else if (ft_strncmp("--adaptive", s, ft_strlen(s)) == 0)
		flags_list->is_adaptive = 1;
	else
		return (0);
	return (1);
}
