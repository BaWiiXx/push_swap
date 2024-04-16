/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:23:59 by bdany             #+#    #+#             */
/*   Updated: 2024/01/22 15:31:21 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putnbr_base(long long int n, const char *base);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_putnbr(int n);
int		ft_putstr(const char *s);
size_t	ft_strlen(const char *s);
int		ft_putnbr_basep(size_t n, const char *base);
int		ft_printf(const char *str, ...);

#endif
