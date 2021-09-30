/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_addfunc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egektor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:57:02 by egektor           #+#    #+#             */
/*   Updated: 2021/01/13 16:57:05 by egektor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	i = 0;
	if (!dst && !src)
		return (dst);
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (dst);
}

int		print_0_x(void)
{
	write(1, "0", 1);
	write(1, "x", 1);
	return (2);
}

int		print_zero_space(int count, char c)
{
	int	res;

	res = 0;
	if (count < 0)
		return (0);
	while (count--)
		res += write(1, &c, 1);
	return (res);
}
