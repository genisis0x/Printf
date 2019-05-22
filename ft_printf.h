/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:00:44 by maparmar          #+#    #+#             */
/*   Updated: 2019/05/09 05:58:11 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <sys/types.h>
# include <math.h>

struct					s_conv
{
	char			flags[6 + 1];
	int				width;
	int				precision;
	char			len_mod[2 + 1];
	char			type;
	char			*str;
	int				len;
	char			*lead;
	int				lead_len;
};
typedef struct s_conv	t_conv;

typedef int				(*t_convf)(t_conv *conv, va_list ap);

struct					s_table
{
	const char		*key;
	const t_convf	func;
};
typedef struct s_table	t_able;

enum	e_field			{STR, LEAD};
typedef enum e_field	t_field;

void					free_swap(t_conv *conv, char *fix, t_field field);
void					leader(t_conv *conv);
void					zero(t_conv *conv, int n);
void					width(t_conv *conv);
int						print(t_conv *conv);

int						conv_char(t_conv *conv, va_list ap);
int						conv_float(t_conv *conv, va_list ap);
int						conv_int(t_conv *conv, va_list ap);
int						conv_mod(t_conv *conv, va_list ap);
int						conv_ptr(t_conv *conv, va_list ap);
int						conv_str(t_conv *conv, va_list ap);
int						conv_uint(t_conv *conv, va_list ap);

void					parse_fmt(t_conv *conv, const char **format);

int						has(char *field, char *str);
int						ft_printf(const char *fmt, ...);

#endif
