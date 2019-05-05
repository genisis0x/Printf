/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:10:52 by maparmar          #+#    #+#             */
/*   Updated: 2019/05/04 18:13:35 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

static int num_len(long long n)
{
    int len;
    
    len = 1;
    while ((n /= 10))
        len++;
    return (len);
}

char *ft_lltoa(long long n)
{
    char *ret;
    int overflow;
    int len;
    int neg;

    overflow = (n == LONG_MIN);
    if ((neg = n < 0))
        n = -(n + overflow);
    len = num_len(n);
    if ((ret = ft_strnew(len + neg)))
    {
        if (neg)
            ret[0] = '-';
        if (overflow)
        {
            ret[neg + --len] = '8';
            n /= 10;
        }
        while (len--)
        {
            ret[neg + len] = n % 10 + '0';
            n /= 10;
        }
    }
    return (ret);
}