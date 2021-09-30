/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egektor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:00:37 by egektor           #+#    #+#             */
/*   Updated: 2021/01/13 17:30:57 by egektor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_struct
{
	int		zero;
	int		minus;
	char	type;
	int		width;
	int		prec;
	int		count;
	int		neg;
	int		point;
}				t_struct;

int				ft_printf(const char *s, ...);
int				search_write(char *s, va_list *list);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				print_zero_space(int count, char c);
int				print_0_x(void);
int				print_percent(t_struct *args);
int				print_pointer(va_list *list, t_struct *args);
int				search_printtype(va_list *list, t_struct *args);
t_struct		create_args(void);
int				is_type(const char *s, int i, t_struct *args);
int				is_flag(const char *s, int i, t_struct *args);
int				is_flag_type(va_list *l, const char *s, int i, t_struct *args);
int				is_width(va_list *list, const char *s, int i, t_struct *args);
int				is_prec(va_list *list, const char *s, int i, t_struct *args);
int				ft_tolower(int c);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
int				ft_isdigit(int c);
long long		print_num(size_t number, t_struct *args, int base);
int				print_string(va_list *list, t_struct *args);
int				print_char(va_list *list, t_struct *args);
char			*ft_itoa_base(size_t value, int base);
char			*make_lowercase(char **s);

#endif
