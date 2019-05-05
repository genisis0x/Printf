/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:30:50 by maparmar          #+#    #+#             */
/*   Updated: 2019/05/04 20:59:51 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int has(char *field, char *str)
{
    while (*str)
    {
        if (!ft_strchr(field, *str))
            return (0);
        str++;
    }
    return (1);
}

int convert(const char **format, va_list ap)
{
    int i;
    t_conv conv;
    const cov_t_able cov_table[] = {{"c", &conv_char},
                                    {"s", &conv_str},
                                    {"p", &conv_ptr},
                                    {"diD", &conv_int},
                                    {"ouxOUX", &conv_uint},
                                    {"%", &conv_mod},
                                    {"fF", &conv_float},
                                    {NULL, NULL}};
                                    
    ft_bzero(&conv, sizeof(t_conv));
    (*format)++;
    parse_fmt(&conv, format);
    while (**format)
    {
        conv.type = *(*format)++;
        i = -1;
        while (cov_table[++i].func)
            if (ft_strchr(cov_table[i].key, conv.type))
                return (cov_table[i].func(&conv, ap));
    }
    return (0);
}
int ft_read_sec(const char **fmt, va_list args)
{
    int index;
    int len_print;

    index = -1;
    len_print = 0;
    while(*fmt[++index])
    {
        if (*fmt[index] == '%')
            break;
    }
    len_print = write(1, *fmt, index);
    *fmt += index;
    if(**fmt == '%')
    {
        len_print += convert(fmt, args);
    }
    return len_print;
}

int ft_printf(const char *fmt, ...)
{
    va_list args;
    size_t len;

    va_start(args, fmt);
	len = 0;
	while(*fmt)
		len += ft_read_sec(&fmt, args);
    va_end(args);
    return len;
}
