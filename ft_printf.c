#include "push_swap.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int				offset;
	size_t			i;

	i = 0;
	offset = 0;
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
	{
		offset += ft_putchar(str[i]);
		i++;
	}
	return (offset);
}

int	ft_putnbr(long long nb)
{
	unsigned long int	n;
	int					offset;

	offset = 0;
	if (nb < 0)
	{
		n = -nb ;
		offset += ft_putchar('-');
	}
	else
		n = nb;
	if (n >= 10)
	{
		offset += ft_putnbr((n / 10));
		offset += ft_putnbr((n % 10));
	}
	else
		offset += ft_putchar(n + 48);
	return (offset);
}

static	int	ft_walk(va_list ptr, char str)
{
	int			offset;
	int			i;

	i = 0;
	offset = 0;
	if (str == 'c')
		offset += ft_putchar(va_arg(ptr, int));
	else if (str == 'i' || str == 'd')
		offset += ft_putnbr(va_arg(ptr, int));
	else if (str == 's')
		offset += ft_putstr(va_arg(ptr, void *));
	else
		offset += ft_putchar(str);
	return (offset);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	int			offset;
	va_list		ptr;

	i = 0;
	offset = 0;
	va_start(ptr, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			offset += ft_walk(ptr, str[i]);
		}
		else
			offset += ft_putchar(str[i]);
			i++;
	}
	va_end(ptr);
	return (offset);
}
