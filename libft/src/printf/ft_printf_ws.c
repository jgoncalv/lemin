/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ws.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 19:58:20 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/14 15:25:00 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static int	ft_display(wchar_t *wstr, int len, t_flag *flag)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (flag->negative == 0)
	{
		if (flag->width_min > 0 || flag->space == 1)
			len += ft_add_width(len, flag);
	}
	if (flag->precision_ok == 1)
		ft_putnwstr(wstr, flag->precision);
	else
		ft_putwstr(wstr);
	if (flag->negative == 1)
	{
		if (flag->width_min > 0 || flag->space == 1)
			len += ft_add_width(len, flag);
	}
	return (len);
}

int			ft_printf_ws(wchar_t *wstr, t_flag *flag)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (!wstr)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (flag->precision_ok == 1)
	{
		while (len + ft_wcharlen(wstr[i]) <= flag->precision)
		{
			len += ft_wcharlen(wstr[i]);
			i++;
		}
	}
	else
		len = ft_wstrlen(wstr);
	return (ft_display(wstr, len, flag));
}
