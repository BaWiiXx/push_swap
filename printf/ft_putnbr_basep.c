/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_basep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:42:41 by bdany             #+#    #+#             */
/*   Updated: 2024/01/22 15:32:59 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putnbr_basep(size_t n, const char *base)
{
	char	c;
	int		i;
	size_t	baselen;

	i = 0;
	baselen = ft_strlen(base);
	if (n >= baselen)
	{
		i += ft_putnbr_basep(n / baselen, base);
	}
	c = base[n % baselen];
	write(1, &c, 1);
	i++;
	return (i);
}
