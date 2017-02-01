/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:22:11 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/14 13:39:55 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_add_prec(int nlen, t_flag *flag)
{
	if (flag->precision < nlen)
		return (flag->precision);
	return (nlen);
}

static int	ft_add_width(int len, t_flag *flag)
{
	char	*str;

	if (flag->width_min > len)
	{
		len = flag->width_min - len;
		if (!(str = (char*)malloc(sizeof(char) * len)))
			exit(-1);
		str[len] = '\0';
		if (flag->zero == 1)
			str = ft_memset(str, '0', len);
		else
			str = ft_memset(str, ' ', len);
		ft_putstr(str);
		ft_strdel(&str);
	}
	else
		len = 0;
	return (len);
}

static int	ft_display(char *str, int nlen, t_flag *flag)
{
	int	len;

	len = nlen;
	if (flag->negative == 0)
	{
		if (flag->width_min > 0)
			len += ft_add_width(nlen, flag);
	}
	ft_putnstr(str, nlen);
	if (flag->negative == 1)
	{
		if (flag->width_min > 0)
			len += ft_add_width(nlen, flag);
	}
	return (len);
}

int			ft_printf_s(char *str, t_flag *flag)
{
	int		len;

	if (!str && flag->width_min == 0)
	{
		ft_putstr("(null)");
		return (6);
	}
	else if (!str && flag->width_min > 0)
		str = "";
	len = ft_strlen(str);
	if (flag->precision_ok == 1)
		len = ft_add_prec(len, flag);
	return (ft_display(str, len, flag));
}
