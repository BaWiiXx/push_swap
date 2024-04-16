/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:12:49 by bdany             #+#    #+#             */
/*   Updated: 2024/02/21 09:46:52 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	prints(const char *s)
{
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr((const char *)s);
	return (ft_strlen(s));
}

static int	printp(void *ptr)
{
	if (!ptr)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ft_putstr("0x");
	return (2 + ft_putnbr_basep((size_t)ptr, "0123456789abcdef"));
}

static int	ft_convertion(va_list args, char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (prints(va_arg(args, const char *)));
	else if (format == 'p')
		return (printp(va_arg(args, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_check(const char *str)
{
	return (*str == '%' && (*(str + 1) == 'c' || *(str + 1) == 's' || *(str
				+ 1) == 'p' || *(str + 1) == 'i' || *(str + 1) == 'u' || *(str
				+ 1) == 'x' || *(str + 1) == 'X' || *(str + 1) == '%' || *(str
				+ 1) == 'd'));
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	va_start(args, str);
	count = 0;
	if (!str)
		return (-1);
	while (*str != '\0')
	{
		if (ft_check(str))
		{
			count += ft_convertion(args, *(str + 1));
			str += 2;
		}
		else
		{
			ft_putchar(*str);
			count++;
			str++;
		}
	}
	va_end(args);
	return (count);
}

int main (void)
{
	ft_printf(;
}
