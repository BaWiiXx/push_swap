/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:50:03 by bdany             #+#    #+#             */
/*   Updated: 2024/01/22 15:30:26 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr_unsigned(unsigned int n)
{
	char			c;
	unsigned int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_putnbr_unsigned(n / 10);
	}
	c = n % 10 + '0';
	write(1, &c, 1);
	i++;
	return (i);
}
