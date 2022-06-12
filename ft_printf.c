#include "ft_printf.h"

int	format(char c, va_list arg)
{
	int	print_number;

	print_number = 0;
	if (c == 'c')
		print_number += ft_printchar(va_arg(arg, int));
	else if (c == 's')
		print_number += ft_printstr(va_arg(arg, char *));
	else if (c == '%')
		print_number += write(1, "%", 1);
	else if (c == 'p')
	{
		print_number += write(1, "0x", 2);
		print_number += ft_printpointer(va_arg(arg, unsigned long int));
	}
	else if (c == 'd' || c == 'i')
		print_number += ft_printnbr(va_arg(arg, int));
	else if (c == 'u')
		print_number += ft_printunbr(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		print_number += ft_printx(va_arg(arg, int), c);
	return (print_number);
}

int	ft_printf(const char *str, ...)
{
	int			print_number;
	int			i;
	va_list		arg;

	i = 0;
	print_number = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_number += format(str[++i], arg);
			i++;
		}
		else
			print_number += ft_printchar(str[i++]);
	}
	return (print_number);
}

int	main()
{
	char	p[] = "canımsın ramo";
	ft_printf("selam bebek %s", p);
}
/*
#include <limits.h>
#include <stdio.h>
int main(void)
{
  int Blen;
  int Alen;
   printf("char:%%c\n");
   Blen = ft_printf("B: char: %c\n", 'a');
   Alen = printf("A: char: %c\n", 'a');
   printf("B: %d\n", Blen);
   printf("A: %d\n", Alen);
   printf("-------------------------------------------\n");
   printf("string:%%s\n");
   Blen = ft_printf("B: string: %s%c\n", "ali Veli", 'a');
   Alen = printf("A: string: %s%c\n", "ali Veli", 'a');
   printf("B: %d\n", Blen);
   printf("A: %d\n", Alen);
   printf("-------------------------------------------\n");
   printf("pointer:%%p\n");
   Blen = ft_printf("B: pointer: %p\n", &Blen);
   Alen = printf("A: pointer: %p\n", &Blen);
   printf("B: %d\n", Blen);
   printf("A: %d\n", Alen);
   printf("-------------------------------------------\n");
   printf("hexB:%%X\n");
   Blen = ft_printf("B: hexB: %X\n", -656667);
   Alen = printf("A: hexB: %X\n", -656667);
   printf("B: %d\n", Blen);
   printf("A: %d\n", Alen);
   printf("-------------------------------------------\n");
   printf("hexK:%%x\n");
   Blen = ft_printf("B: hexK: %x\n", -979899);
   Alen = printf("A: hexK: %x\n", -979899);
   printf("B: %d\n", Blen);
   printf("A: %d\n", Alen);
   printf("-------------------------------------------\n");
   printf("int:%%i\n");
   Blen = ft_printf("B: %i\n", -0);
   Alen = printf("A: %i\n", -0);
   printf("B: %d\n", Blen);
   printf("A: %d\n", Alen);
   printf("-------------------------------------------\n");
   printf("int:%%d\n");
   Blen = ft_printf("B: %d\n", -9798990);
   Alen = printf("A: %d\n", -9798990);
   printf("B: %d\n", Blen);
   printf("A: %d\n", Alen);
   printf("-------------------------------------------\n");
   printf("unsigned int:%%u\n");
   Blen = ft_printf("B: %u\n", 9798990);
   Alen = printf("A: %u\n", 9798990);
   printf("B: %d\n", Blen);
   printf("A: %d\n", Alen);
   printf("-------------------------------------------\n");
   printf("%%:%%%%\n");
   Blen = ft_printf("B: %%232323%i\n", 9798990);
   Alen = printf("A: %%232323%i\n", 9798990);
   printf("B: %d\n", Blen);
   printf("A: %d\n", Alen);
   printf("-------------------------------------------\n");
   ft_printf("%x-\n", LONG_MAX);
   printf("%lx-", LONG_MAX);
}*/
