/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:55:49 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/14 13:24:34 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_add_prefix(t_flag *flag, intmax_t n)
{
	int len;

	len = 0;
	if ((n == 0 && flag->precision_ok == 0) || n < 0)
	{
		if (n < 0)
			flag->space = 0;
		len++;
	}
	if (flag->positive == 1 && n >= 0)
		len++;
	return (len);
}

static int	ft_add_len(int len, t_flag *flag, intmax_t n)
{
	intmax_t nc;

	nc = n;
	while (nc != 0)
	{
		nc /= 10;
		len++;
	}
	if (flag->zero == 1 && flag->precision_ok == 0)
	{
		if (flag->width_min > len)
			len += flag->width_min - len;
		if (flag->space && flag->width_min > 0)
			len--;
	}
	else if (flag->precision_ok == 1 && flag->precision >= len)
	{
		len += flag->precision - len;
		if (n < 0 || flag->positive == 1)
			len++;
	}
	return (len);
}

static int	ft_add_width(int len, t_flag *flag)
{
	char	*str;

	if (flag->width_min > len || flag->space == 1)
	{
		if (flag->width_min > len)
			len = flag->width_min - len;
		else
			len = 1;
		if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
			exit(-1);
		str[len] = '\0';
		str = ft_memset(str, ' ', len);
		ft_putstr(str);
		ft_strdel(&str);
	}
	else
		len = 0;
	return (len);
}

static int	ft_display(char *str, int len, t_flag *flag)
{
	if (flag->precision_ok == 1)
		flag->zero = 0;
	if (flag->negative == 0)
	{
		if ((flag->width_min > 0 && flag->zero == 0) || flag->space)
			len += ft_add_width(len, flag);
	}
	ft_putstr(str);
	if (flag->negative == 1)
	{
		if ((flag->width_min > 0 && flag->zero == 0) || flag->space)
			len += ft_add_width(len, flag);
	}
	ft_strdel(&str);
	return (len);
}

int			ft_printf_itoa(intmax_t n, t_flag *flag)
{
	int		len;
	int		lenc;
	int		sign;
	char	*str;

	str = NULL;
	len = 0;
	lenc = 0;
	sign = (n < 0 ? -1 : 1);
	len = ft_add_prefix(flag, n);
	len = ft_add_len(len, flag, n);
	lenc = len;
	if (!(str = ft_strnew(sizeof(char) * len)))
		exit(-1);
	while (lenc)
	{
		str[lenc - 1] = sign * (n % 10) + '0';
		n = n / 10;
		lenc--;
	}
	if (sign == -1)
		str[lenc] = '-';
	else if (flag->positive == 1)
		str[lenc] = '+';
	return (ft_display(str, len, flag));
}
