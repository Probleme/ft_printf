/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:24:51 by ataouaf           #+#    #+#             */
/*   Updated: 2022/11/23 15:46:33 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_callspecifier(char c, va_list args)
{
	unsigned long long	p;

	if (c == '%')
		return (print_c('%'));
	else if (c == 'c')
		return (print_c(va_arg(args, int)));
	else if (c == 's')
		return (print_s(va_arg(args, char *)));
	else if (c == 'i' || c == 'd')
		return (print_i_d(va_arg(args, int)));
	else if (c == 'u')
		return (print_u(va_arg(args, int)));
	else if (c == 'x' || c == 'X')
		return (print_x(va_arg(args, int), c));
	else if (c == 'p')
	{
		p = va_arg(args, unsigned long long);
		if (p == '0')
			return (print_s("0x0"));
		else
			return (print_s("0x") + print_p(p));
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	if (!str)
		return (0);
	va_start(args, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (!str)
				break ;
			len += ft_callspecifier(str[i], args);
		}
		else
			len += print_c(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
