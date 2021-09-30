/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_search_type_3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egektor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:55:39 by egektor           #+#    #+#             */
/*   Updated: 2021/01/13 16:55:43 by egektor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	search_print_type_num(va_list list, t_struct *args)
{
	long int	number_i;
	size_t		number_t;

	if (args->type == 'd' || args->type == 'i')
	{
		number_i = va_arg(list, int);
		if (number_i >= 0)
			number_t = number_i;
		else
		{
			args->neg = 1;
			number_t = -number_i;
		}
		return (print_num(number_t, args, 10));
	}
	else if (args->type == 'x' || args->type == 'X' || args->type == 'u')
	{
		number_t = va_arg(list, unsigned int);
		if (args->type == 'u')
			return (print_num(number_t, args, 10));
		else
			return (print_num(number_t, args, 16));
	}
	return (0);
}

int			search_printtype(va_list *list, t_struct *args)
{
	int res;

	res = 0;
	if (args->type == 's')
		res += print_string(list, args);
	else if (args->type == '%')
		res += print_percent(args);
	else if (args->type == 'c')
		res += print_char(list, args);
	else if (args->type == 'p')
	{
		args->point = 1;
		res += print_pointer(list, args);
	}
	else if (args->type == 'd' || args->type == 'i'
			|| args->type == 'x' || args->type == 'X'
			|| args->type == 'u')
		res += search_print_type_num(*list, args);
	else
		return (0);
	return (res);
}
