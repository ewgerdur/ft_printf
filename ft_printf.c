/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egektor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:53:47 by egektor           #+#    #+#             */
/*   Updated: 2021/01/13 16:53:55 by egektor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				search_write(char *s, va_list *list)
{
	int			i;
	t_struct	args;
	int			res;

	res = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			args = create_args();
			res = res + is_flag_type(list, s, i, &args);
			i = i + args.count;
		}
		else
		{
			res = res + write(1, &s[i], 1);
			i++;
		}
	}
	return (res);
}

int				ft_printf(const char *s, ...)
{
	va_list	ap;
	int		res;
	char	*print;

	res = 0;
	if (!(print = ft_strdup(s)) || !s)
		return (-1);
	va_start(ap, s);
	res = res + search_write(print, &ap);
	va_end(ap);
	free(print);
	return (res);
}
