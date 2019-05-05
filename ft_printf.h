/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:00:44 by maparmar          #+#    #+#             */
/*   Updated: 2019/05/04 20:55:09 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <math.h>

# define ANY2(x, y1, y2) ((x) == (y1) || (x) == (y2))
# define ANY3(x, y1, y2, y3) ((x) == (y1) || (x) == (y2) || (x) == (y3))

typedef struct s_conv
{
    char flags[6 + 1];
    int width;
    int precision;
    char len_mod[2 + 1];
    char type;
    char *str;
    int len;
    char *lead;
    int lead_len;
} t_conv;

typedef int (*t_convf)(t_conv *conv, va_list ap); // function for all the conv type

typedef struct s_table // Cov_table to hold the values
{
    const char *key;
    const t_convf func;
} cov_t_able;

 int   ft_printf(const char *fmt, ...); // starting point.

 typedef enum e_field {STR,LEAD} t_field;

 /****************** Conversion Functions*****************/

 int conv_char(t_conv *conv, va_list ap);
 int conv_float(t_conv *conv, va_list ap);
 int conv_int(t_conv *conv, va_list ap);
 int conv_mod(t_conv *conv, va_list ap);
 int conv_ptr(t_conv *conv, va_list ap);
 int conv_str(t_conv *conv, va_list ap);
 int conv_uint(t_conv *conv, va_list ap);

 
 /****************Parser Function*********************/

 void parse_fmt(t_conv *conv, const char **format);


 int has(char *field, char *str);


/***************** Utilites Functions**********************/
 void free_swap(t_conv *conv, char *fix, t_field field);
 void leader(t_conv *conv);
 void zero(t_conv *conv, int n);
 void width(t_conv *conv);
 int print(t_conv *conv);

#endif
