/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egektor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:57:41 by egektor           #+#    #+#             */
/*   Updated: 2021/01/13 16:57:44 by egektor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_percent(t_struct *args)
{
	int	res;

	res = 0;
	if (!args->minus && !args->zero)
		res += print_zero_space(args->width - 1, ' ');
	if (!args->minus && args->zero)
		res += print_zero_space(args->width - 1, '0');
	res = res + write(1, "%", 1);
	if (args->minus)
		res += print_zero_space(args->width - 1, ' ');
	return (res);
}

int				print_pointer(va_list *list, t_struct *args)
{
	size_t	pointer;
	int		res;

	res = 0;
	pointer = (size_t)va_arg(*list, void *);
	res += print_num(pointer, args, 16);
	return (res);
}

char			*make_lowercase(char **s)
{
	int	i;

	i = 0;
	while ((*s)[i])
	{
		(*s)[i] = ft_tolower((*s)[i]);
		i++;
	}
	return (*s);
}
