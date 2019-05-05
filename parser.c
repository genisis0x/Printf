/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:00:48 by maparmar          #+#    #+#             */
/*   Updated: 2019/05/04 19:29:13 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void parse_flags(t_conv *conv, const char **format)
{
    while (**format && ft_strchr("#0- +", **format))
    {
        if (ft_strlen(conv->flags) < 6 && !ft_strchr(conv->flags, **format))
            ft_strncat(conv->flags, *format, 1);
        (*format)++;
    }
}

static void parse_width(t_conv *conv, const char **format)
{
    if (ft_isdigit(**format))
        conv->width = ft_atoi(*format);
    while (ft_isdigit(**format))
        (*format)++;
}

static void parse_precision(t_conv *conv, const char **format)
{
    conv->precision = -1;
    if (**format == '.')
    {
        (*format)++;
        conv->precision = ft_isdigit(**format) ? ft_atoi(*format) : 0;
    }
    while (**format == '-' || ft_isdigit(**format))
        (*format)++;
}

static void parse_len_mod(t_conv *conv, const char **format)
{
    while (**format && ft_strchr("lLhjz", **format))
    {
        if (ft_strlen(conv->len_mod) < 2)
            ft_strncat(conv->len_mod, *format, 1);
        (*format)++;
    }
}

void parse_fmt(t_conv *conv, const char **format)
{
    parse_flags(conv, format);
    parse_width(conv, format);
    parse_precision(conv, format);
    parse_len_mod(conv, format);
}