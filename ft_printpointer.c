/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:52:01 by faydin            #+#    #+#             */
/*   Updated: 2022/02/15 17:52:02 by faydin           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpointer(unsigned long int n)
{
	int	print_number;

	print_number = 0;
	if (n >= 16)
		print_number += ft_printpointer(n / 16);
	print_number += ft_printchar("0123456789abcdef"[n % 16]);
	return (print_number);
}
