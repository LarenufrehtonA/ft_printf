/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:51:50 by faydin            #+#    #+#             */
/*   Updated: 2022/02/17 04:56:41 by faydin           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		len += ft_printstr("-2");
		nb = 147483648;
	}
	if (nb < 0)
	{
		len += ft_printchar('-');
		nb *= -1;
	}
	if (nb >= 0 && nb < 10)
		len += ft_printchar(nb + 48);
	else
	{
		len += ft_printnbr(nb / 10);
		len += ft_printnbr(nb % 10);
	}
	return (len);
}
