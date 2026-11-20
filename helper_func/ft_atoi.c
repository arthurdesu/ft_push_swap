#include "../push_swap.h"

static int	ft_convert_to_nbr(const char *nptr, int sign)
{
	size_t	i;
	size_t	nbr;

	i = 0;
	nbr = 0;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + nptr[i] - '0';
		if (nbr > LONG_MAX)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		i++;
	}
	return (nbr * sign);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;

	if (!*nptr)
		return (0);
	i = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	return (ft_convert_to_nbr(nptr + i, sign));
}
