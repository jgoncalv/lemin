/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:53:52 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/12 13:52:57 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_add_len(t_flag *flag, uintmax_t n, int base)
{
	int	len;

	len = 0;
	if (n == 0 && flag->precision_ok == 0)
		len++;
	len += 2;
	while (n != 0)
	{
		n /= base;
		len++;
	}
	if (flag->zero == 1)
	{
		if (flag->width_min > len)
			len += flag->width_min - len;
	}
	else if (flag->precision_ok == 1)
	{
		if (flag->precision > len - 2)
			len += flag->precision - (len - 2);
	}
	return (len);
}

static int	ft_add_width(int len, t_flag *flag)
{
	char *str;

	if (flag->width_min > len)
	{
		len = flag->width_min - len;
		if (!(str = (char*)malloc(sizeof(char) * len)))
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
	if (flag->negative == 0)
	{
		if (flag->width_min > 0 && flag->zero == 0)
			len += ft_add_width(len, flag);
	}
	ft_putstr(str);
	if (flag->negative == 1)
	{
		if (flag->width_min > 0 && flag->zero == 0)
			len += ft_add_width(len, flag);
	}
	ft_strdel(&str);
	return (len);
}

int			ft_printf_p(unsigned long n, t_flag *flag)
{
	char				*str;
	int					len;
	int					lenc;

	len = ft_add_len(flag, n, 16);
	lenc = len;
	if (!(str = ft_strnew(sizeof(char) * len)))
		exit(-1);
	while (lenc)
	{
		str[lenc - 1] = (n % 16) + (n % 16 > 9 ? 'a' - 10 : '0');
		n /= 16;
		lenc--;
	}
	str[lenc + 1] = 'x';
	return (ft_display(str, len, flag));
}
