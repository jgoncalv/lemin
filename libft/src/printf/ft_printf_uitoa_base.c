/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uitoa_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:00:26 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/14 15:09:59 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_add_sharp(t_flag *flag, char c)
{
	if (flag->sharp == 1)
	{
		if (ft_strchr("xX", c))
		{
			if (flag->precision_ok == 1 && flag->precision == 0)
			{
				flag->sharp = 0;
				return (0);
			}
			if (flag->zero == 1 && flag->width_min > 0)
				return (0);
			return (2);
		}
		else if (c == 'o')
		{
			if (flag->precision_ok == 1 && flag->precision > 0)
				return (0);
			return (1);
		}
	}
	return (0);
}

static int	ft_add_len(t_flag *flag, uintmax_t n, int base, char c)
{
	int	len;

	len = 0;
	if (n == 0 && flag->precision_ok == 0)
	{
		flag->sharp = 0;
		len++;
	}
	len += ft_add_sharp(flag, c);
	while (n != 0)
	{
		n /= base;
		len++;
	}
	if (flag->zero == 1)
	{
		if (flag->width_min > len)
			len += flag->width_min - len + ft_add_sharp(flag, c);
	}
	else if (flag->precision_ok == 1)
	{
		if (flag->precision > len)
			len += flag->precision - len + ft_add_sharp(flag, c);
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

int			ft_printf_uitoa_base(uintmax_t n, int base, t_flag *flag, char c)
{
	int		len;
	int		lenc;
	char	*str;

	len = ft_add_len(flag, n, base, c);
	lenc = len;
	if (!(str = ft_strnew(sizeof(char) * len)))
		exit(-1);
	while (lenc)
	{
		str[lenc - 1] = (n % base) + (n % base > 9 ? 'a' - 10 : '0');
		n /= base;
		lenc--;
	}
	if (flag->sharp && (c == 'x' || c == 'X'))
		str[lenc + 1] = 'x';
	if (c == 'X')
		str = ft_strtoupper(str);
	return (ft_display(str, len, flag));
}
