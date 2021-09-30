/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_str_4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egektor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:56:07 by egektor           #+#    #+#             */
/*   Updated: 2021/01/14 18:58:36 by egektor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_string_print(char *s, int length)
{
	int	j;
	int	res;

	res = 0;
	j = 0;
	while (s[j] && length > 0)
	{
		res = res + write(1, &s[j], 1);
		j++;
		length--;
	}
	return (res);
}

int			print_char(va_list *list, t_struct *args)
{
	char	c;
	int		res;

	res = 0;
	c = va_arg(*list, int);
	if (!(args->minus == 1))
		res += print_zero_space(args->width - 1, ' ');
	res += write(1, &c, 1);
	if (args->minus)
		res += print_zero_space(args->width - 1, ' ');
	return (res);
}

int			print_string(va_list *list, t_struct *args)
{
	char	*s;
	int		res;
	int		len;

	res = 0;
	s = va_arg(*list, char *);
	if (s == NULL)
		if (!(s = ft_strdup("(null)")))
			return (-1);
	len = ft_strlen(s);
	if (args->prec < 0)
		args->prec = -1;
	if (args->prec >= 0 && len > args->prec)
		len = args->prec;
	if (!(args->minus))
		res += print_zero_space(args->width - len, ' ');
	res += print_string_print(s, len);
	if (args->minus)
		res += print_zero_space(args->width - len, ' ');
	return (res);
}
