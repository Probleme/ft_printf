/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:24:31 by ataouaf           #+#    #+#             */
/*   Updated: 2022/11/25 20:09:54 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	lenght_num(unsigned long long n)
{
	int	i;

	i = 1;
	while (n >= 16)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static void	ft_putnbr_base(unsigned long long n, char *base)
{
	if (n >= 16)
		ft_putnbr_base(n / 16, base);
	print_c(base[n % 16]);
}

int	print_p(unsigned long long nb)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789abcdef";
	ft_putnbr_base(nb, base);
	len = lenght_num(nb);
	return (len);
}

int	print_x(int i, char x)
{
	char			*base;
	int				len;
	unsigned int	nb;

	len = 0;
	nb = (unsigned int)i;
	base = "0123456789abcdef";
	if (x == 'X')
		base = "0123456789ABCDEF";
	ft_putnbr_base(nb, base);
	len = lenght_num(nb);
	return (len);
}
