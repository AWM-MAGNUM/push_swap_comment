#include "push_swap.h"

int	ft_atoi(char *str)
{
	int			i;
	long long	res;
	int			signe;

	res = 0;
	signe = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res = res + str[i] - 48;
		i++;
	}
	return (signe * res);
}

long long int	ft_atoll(const char *str)
{
	t_node	atoll;

	atoll.sign = 1;
	atoll.i_at = 0;
	atoll.result = 0;
	while (str[atoll.i_at] == ' ' || str[atoll.i_at] == '+')
		atoll.i_at++;
	if (str[atoll.i_at] == '-')
	{
		atoll.sign = -1;
		atoll.i_at++;
	}
	while (str[atoll.i_at] != '\0')
	{
		if (str[atoll.i_at] < '0' || str[atoll.i_at] > '9')
			return (0);
		atoll.digit = str[atoll.i_at] - '0';
		atoll.result = atoll.result * 10 + atoll.digit;
		if (atoll.result > LLONG_MAX)
		{
			if (atoll.sign == 1)
				return (LLONG_MAX);
			else
				return (LLONG_MIN);
		}
		atoll.i_at++;
	}
	return (atoll.result * atoll.sign);
}

int	ft_lstsize(t_node *head)
{
	int		size;
	t_node	*current;

	size = 0;
	current = head;
	while (current != NULL && size < INT_MAX)
	{
		size++;
		current = current->next;
	}
	return (size);
}
