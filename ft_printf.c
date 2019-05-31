/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:30:50 by maparmar          #+#    #+#             */
/*   Updated: 2019/05/09 05:41:45 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		has(char *field, char *str)
{
	while (*str)
	{
		if (!ft_strchr(field, *str))
			return (0);
		str++;
	}
	return (1);
}

int		convert(const char **fmt, va_list ap)
{
	int					i;
	t_conv				conv;
	const t_able		table[] = {	{"c", &conv_char}, {"s", &conv_str},
								{"p", &conv_ptr}, {"diD", &conv_int},
								{"ouxOUX", &conv_uint}, {"%", &conv_mod},
								{"fF", &conv_float}, {NULL, NULL}};

	ft_bzero(&conv, sizeof(t_conv));
	(*fmt)++;
	parse_fmt(&conv, fmt);
	while (**fmt)
	{
		conv.type = *(*fmt)++;
		i = -1;
		while (table[++i].func)
			if (ft_strchr(table[i].key, conv.type))
				return (table[i].func(&conv, ap));
	}
	return (0);
}

int		ft_read_sec(const char **fmt, va_list ap)
{
	int				index;
	int				len_printed;

	len_printed = 0;
	index = -1;
	while ((*fmt)[++index])
		if ((*fmt)[index] == '%')
			break ;
	len_printed = write(1, *fmt, index);
	*fmt += index;
	if (**fmt == '%')
		len_printed += convert(fmt, ap);
	return (len_printed);
}

int		ft_printf(const char *fmt, ...)
{
	va_list			ap;
	int				len;

	va_start(ap, fmt);
	len = 0;
	while (*fmt)
		len += ft_read_sec(&fmt, ap);
	va_end(ap);
	return (len);
}
