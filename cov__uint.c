/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cov__uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:27:47 by maparmar          #+#    #+#             */
/*   Updated: 2019/05/04 19:14:11 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdlib.h>
#include <stdarg.h>

static unsigned long long	arg(t_conv *conv, va_list ap)
{
	if (conv->type == 'O')
		ft_memmove(conv->len_mod, "l", 2);
	else if (conv->type == 'U')
		ft_memmove(conv->len_mod, "l", 2);
	if (ft_strchr(conv->len_mod, 'z'))
		return ((size_t)va_arg(ap, size_t));
	if (ft_strchr(conv->len_mod, 'j'))
		return ((uintmax_t)va_arg(ap, uintmax_t));
	if (ft_strequ(conv->len_mod, "l"))
		return (va_arg(ap, unsigned long));
	if (ft_strequ(conv->len_mod, "ll"))
		return (va_arg(ap, unsigned long long));
	return (va_arg(ap, unsigned int));
}

static void					build_conv(t_conv *conv)
{
	conv->len = ft_strlen(conv->str);
	leader(conv);
	if (conv->precision == 0 && *conv->str == '0')
	{
		*conv->str = '\0';
		conv->len = 0;
	}
	else if (conv->precision == -1 && has(conv->flags, "0") &&
				!has(conv->flags, "-") &&
				conv->width > (conv->lead_len + conv->len))
		zero(conv, conv->width - (conv->lead_len + conv->len));
	else if (conv->precision > conv->len)
		zero(conv, conv->precision - conv->len);
	width(conv);
}

int							conv_uint(t_conv *conv, va_list ap)
{
	int	base;

	if (conv->type == 'o' || conv->type == 'O')
		base = 8;
	else if (conv->type == 'u' || conv->type == 'U')
		base = 10;
	else if (conv->type == 'x')
		base = 16;
	else
		base = 17;
	conv->str = ft_ulltoa_base(arg(conv, ap), base);
	build_conv(conv);
	return (print(conv));
}
