/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:27:55 by maparmar          #+#    #+#             */
/*   Updated: 2019/05/04 20:38:54 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_swap(t_conv *conv, char *fix, t_field field)
{
	if (field == STR)
	{
		free(conv->str);
		conv->str = fix;
	}
	else
	{
		free(conv->lead);
		conv->lead = fix;
	}
}

void	leader(t_conv *conv)
{
	if (ft_strchr("dDifF", conv->type))
	{
		if (conv->lead)
			;
		else if (has(conv->flags, "+"))
			conv->lead = ft_strdup("+");
		else if (has(conv->flags, " "))
			conv->lead = ft_strdup(" ");
		else
			return ;
		conv->lead_len = 1;
	}
	if (!ft_strchr(conv->flags, '#') || ft_strchr("uU", conv->type))
		return ;
	if (ft_strchr("oO", conv->type) && conv->len >= conv->precision &&
			(*conv->str != '0' || conv->precision == 0))
		conv->lead = ft_strdup("0");
	else if (*conv->str == '0')
		;
	else if (conv->type == 'x')
		conv->lead = ft_strdup("0x");
	else if (conv->type == 'X')
		conv->lead = ft_strdup("0X");
	conv->lead_len = ft_strlen(conv->lead);
}

void	zero(t_conv *conv, int n)
{
	char	*fix;

	if (n > 0)
	{
		fix = ft_strnew(conv->lead_len + n);
		ft_memmove(fix, conv->lead, conv->lead_len);
		ft_memset(fix + conv->lead_len, '0', n);
		free_swap(conv, fix, LEAD);
		conv->lead_len += n;
	}
}

void	width(t_conv *conv)
{
	char	*fix;
	int		diff;

	diff = conv->width - (conv->lead_len + conv->len);
	if (diff > 0)
	{
		if (ft_strchr(conv->flags, '-'))
		{
			fix = ft_strnew(conv->len + diff);
			ft_memmove(fix, conv->str, conv->len);
			ft_memset(fix + conv->len, ' ', diff);
			free_swap(conv, fix, STR);
		}
		else
		{
			fix = ft_strnew(diff + conv->lead_len);
			ft_memset(fix, ' ', diff);
			ft_memmove(fix + diff, conv->lead, conv->lead_len);
			free_swap(conv, fix, LEAD);
		}
	}
}

int		print(t_conv *conv)
{
	int		printed;

	printed = ft_putstr(conv->lead);
	printed += ft_putstr(conv->str);
	free(conv->lead);
	free(conv->str);
	return (printed);
}
