/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:51:34 by faydin            #+#    #+#             */
/*   Updated: 2022/02/17 04:48:14 by faydin           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printchar(char c);
int	ft_printstr(const char *str);
int	ft_printpointer(unsigned long int n);
int	ft_printnbr(int nb);
int	ft_printunbr(unsigned int n);
int	ft_printx(unsigned int n, char c);
int	ft_printf(const char *str, ...);
int	format(char c, va_list arg);

#endif
