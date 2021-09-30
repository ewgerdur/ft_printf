/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_num_5.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egektor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:56:22 by egektor           #+#    #+#             */
/*   Updated: 2021/01/13 16:56:25 by egektor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_num_with_w_p(char *s, int end)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (s[i] && i < end)
	{
		res += write(1, &s[i], 1);
		i++;
	}
	free(s);
	return (res);
}

static int	maxim(int a, int b)
{
	if (a <= b)
		return (b);
	else
		return (a);
}

static int	check_if_zero(t_struct *args, int number, int length)
{
	if (args->prec == 0 && number == 0)
		return (0);
	else
		return (length);
}

long long	print_num(size_t number, t_struct *args, int base)
{
	int		res;
	char	*s;
	int		len;

	res = 0;
	s = ft_itoa_base(number, base);
	len = ft_strlen(s);
	if (args->type == 'x' || args->type == 'p')
		s = make_lowercase(&s);
	len = check_if_zero(args, number, len);
	args->width -= (maxim(len, args->prec) + args->neg + args->point * 2);
	if ((!args->minus && !args->zero) || (!args->minus && args->prec >= 0))
		res += print_zero_space(args->width, ' ');
	if (args->neg == 1)
		res += write(1, "-", 1);
	if (args->point)
		res += print_0_x();
	if (!args->minus && args->zero && args->prec < 0)
		res += print_zero_space(args->width, '0');
	if (args->prec > len)
		res += print_zero_space(args->prec - len, '0');
	res += print_num_with_w_p(s, len);
	if (args->minus)
		res += print_zero_space(args->width, ' ');
	return (res);
}
