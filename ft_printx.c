#include "ft_printf.h"

int	ft_printx(unsigned int n, char c)
{
	int	print_number;

	print_number = 0;
	if (n == 0)
	{
		ft_printstr("0");
		return (1);
	}
	if (n >= 16)
		print_number += ft_printx(n / 16, c);
	if (c == 'x')
		print_number += ft_printchar("0123456789abcdef"[n % 16]);
	else
		print_number += ft_printchar("0123456789ABCDEF"[n % 16]);
	return (print_number);
}
