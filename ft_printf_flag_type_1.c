/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_type_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egektor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:54:13 by egektor           #+#    #+#             */
/*   Updated: 2021/01/13 16:54:18 by egektor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct		create_args(void)
{
	t_struct	args;

	args.zero = 0;
	args.minus = 0;
	args.width = 0;
	args.type = 0;
	args.prec = -1;
	args.count = 1;
	args.neg = 0;
	args.point = 0;
	return (args);
}

int				is_flag(const char *s, int i, t_struct *args)
{
	char	c;

	c = s[i];
	if (c == '-')
		args->minus = 1;
	else if (c == '0')
		args->zero = 1;
	else
		return (0);
	return (1);
}

int				is_type(const char *s, int i, t_struct *args)
{
	char	c;

	c = s[i];
	if (c == 'c')
		args->type = 'c';
	else if (c == 's')
		args->type = 's';
	else if (c == 'p')
		args->type = 'p';
	else if (c == 'd')
		args->type = 'd';
	else if (c == 'i')
		args->type = 'i';
	else if (c == 'u')
		args->type = 'u';
	else if (c == 'x')
		args->type = 'x';
	else if (c == 'X')
		args->type = 'X';
	else if (c == '%')
		args->type = '%';
	else
		return (0);
	return (1);
}

int				is_flag_type(va_list *l, const char *s, int i, t_struct *args)
{
	int	res;
	int	buba;

	res = 0;
	buba = 0;
	i = i + 1;
	while (is_flag(s, i, args) == 1)
	{
		i++;
		args->count += 1;
	}
	if ((args->minus && args->zero))
		args->zero = 0;
	if ((buba = is_width(l, s, i, args)))
		i = i + buba;
	buba = 0;
	if ((buba = is_prec(l, s, i, args)))
		i = i + buba;
	if (is_type(s, i, args))
	{
		args->count += 1;
		res = res + search_printtype(l, args);
	}
	return (res);
}
