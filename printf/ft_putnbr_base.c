/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:51:29 by bdany             #+#    #+#             */
/*   Updated: 2023/11/24 16:40:27 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putnbr_base(long long int n, const char *base)
{
	char	c;
	int		i;
	int		baselen;

	i = 0;
	baselen = ft_strlen(base);
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		i++;
	}
	if (n >= baselen)
	{
		i += ft_putnbr_base(n / baselen, base);
	}
	c = base[n % baselen];
	write (1, &c, 1);
	i++;
	return (i);
}
