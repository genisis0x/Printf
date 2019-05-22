/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 05:27:56 by maparmar          #+#    #+#             */
/*   Updated: 2019/05/06 05:29:37 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_flags(t_conv *conv, const char **fmt)
{
	while (**fmt && ft_strchr("#0- +", **fmt))
	{
		if (ft_strlen(conv->flags) < 6 && !ft_strchr(conv->flags, **fmt))
			ft_strncat(conv->flags, *fmt, 1);
		(*fmt)++;
	}
}

static void	parse_width(t_conv *conv, const char **fmt)
{
	if (ft_isdigit(**fmt))
		conv->width = ft_atoi(*fmt);
	while (ft_isdigit(**fmt))
		(*fmt)++;
}

static void	parse_precision(t_conv *conv, const char **fmt)
{
	conv->precision = -1;
	if (**fmt == '.')
	{
		(*fmt)++;
		conv->precision = ft_isdigit(**fmt) ? ft_atoi(*fmt) : 0;
	}
	while (**fmt == '-' || ft_isdigit(**fmt))
		(*fmt)++;
}

static void	parse_len_mod(t_conv *conv, const char **fmt)
{
	while (**fmt && ft_strchr("lLhjz", **fmt))
	{
		if (ft_strlen(conv->len_mod) < 2)
			ft_strncat(conv->len_mod, *fmt, 1);
		(*fmt)++;
	}
}

void		parse_fmt(t_conv *conv, const char **fmt)
{
	parse_flags(conv, fmt);
	parse_width(conv, fmt);
	parse_precision(conv, fmt);
	parse_len_mod(conv, fmt);
}
