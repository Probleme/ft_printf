/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i_d_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:25:51 by ataouaf           #+#    #+#             */
/*   Updated: 2022/11/24 18:11:57 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	lenght_num(long n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_putnbr(long n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	print_c(n % 10 + '0');
}

int	print_u(int n)
{
	int				len;
	unsigned int	nbr;

	len = 0;
	nbr = (unsigned int)n;
	ft_putnbr(nbr);
	len = lenght_num(nbr);
	return (len);
}

int	print_i_d(int n)
{
	int		len;
	long	nb;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		print_c('-');
		len = 1;
	}
	ft_putnbr(nb);
	len += lenght_num(nb);
	return (len);
}
