/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cov_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:27:30 by maparmar          #+#    #+#             */
/*   Updated: 2019/05/06 05:18:15 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double	arg(t_conv *conv, va_list ap)
{
	if (has(conv->len_mod, "L"))
		return (va_arg(ap, long double));
	return (va_arg(ap, double));
}

long double			ft_round(long double n, int precision)
{
	long double reckoning;
	int			i;

	if (fpclassify(n) != FP_NORMAL)
		return (n);
	reckoning = .5;
	i = -1;
	while (++i < precision)
		reckoning /= 10;
	return (n < 0 ? n - reckoning : n + reckoning);
}

void				fractional(t_conv *conv, long double n)
{
	char	*fix;
	int		i;
	char	digit;

	if (has(conv->flags, "#") || conv->precision != 0)
	{
		fix = ft_strnew(conv->len + 1 + conv->precision);
		ft_memmove(fix, conv->str, conv->len++);
		ft_strcat(fix, ".");
		n -= (long long)n;
		n *= 10;
		i = -1;
		while (++i < conv->precision)
		{
			digit = (long long)n % 10;
			fix[conv->len + i] = digit + '0';
			n = (n - digit) * 10;
		}
		free_swap(conv, fix, STR);
		conv->len += conv->precision;
	}
}

static void			build_conv(t_conv *conv, long double n, int class)
{
	conv->len = ft_strlen(conv->str);
	if (signbit(n) && class != FP_NAN)
	{
		n = -n;
		conv->lead = ft_strdup("-");
		conv->lead_len++;
		if (*conv->str == '-')
			ft_memmove(conv->str, conv->str + 1, conv->len--);
	}
	if (ANY2(class, FP_NORMAL, FP_ZERO))
		fractional(conv, n);
	if (ANY3(class, FP_INFINITE, FP_NORMAL, FP_ZERO))
		leader(conv);
	if (has(conv->flags, "0") && !has(conv->flags, "-") &&
			conv->width > (conv->lead_len + conv->len))
		zero(conv, conv->width - (conv->lead_len + conv->len));
	width(conv);
}

int					conv_float(t_conv *conv, va_list ap)
{
	long double n;
	int			class;

	if (conv->precision == -1)
		conv->precision = 6;
	n = ft_round(arg(conv, ap), conv->precision);
	if (ANY2(class = fpclassify(n), FP_NAN, FP_INFINITE))
	{
		if (class == FP_NAN)
			conv->str = ft_strdup((conv->type == 'f' ? "nan" : "NAN"));
		else
			conv->str = ft_strdup((conv->type == 'f' ? "inf" : "INF"));
		if (ft_strchr(conv->flags, '0'))
			*ft_strchr(conv->flags, '0') = 1;
	}
	else
		conv->str = ft_lltoa(n);
	build_conv(conv, n, class);
	return (print(conv));
}
