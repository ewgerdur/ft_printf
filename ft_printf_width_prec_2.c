/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width_prec_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egektor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:58:04 by egektor           #+#    #+#             */
/*   Updated: 2021/01/13 16:58:09 by egektor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_prec(va_list *list, const char *s, int i, t_struct *args)
{
	int	buba;

	buba = 0;
	if (s[i] == '.')
	{
		i++;
		buba++;
	}
	else
		return (0);
	args->prec = 0;
	if (s[i] == '*')
	{
		args->prec = va_arg(*list, int);
		buba += 1;
	}
	else if (ft_isdigit(s[i]))
		while (ft_isdigit(s[i]))
		{
			args->prec = args->prec * 10 + (s[i] - '0');
			i++;
			buba++;
		}
	args->count += buba;
	return (buba);
}

int	is_width(va_list *list, const char *s, int i, t_struct *args)
{
	int	buba;

	buba = 0;
	if (s[i] == 0 && args->minus)
		i++;
	if (s[i] == '*')
	{
		args->width = va_arg(*list, int);
		buba = 1;
	}
	else if (ft_isdigit(s[i]))
		while (ft_isdigit(s[i]))
		{
			args->width = args->width * 10 + (s[i] - '0');
			i++;
			buba++;
		}
	if (args->width < 0)
	{
		args->minus = 1;
		args->width = -args->width;
	}
	args->count += buba;
	return (buba);
}
