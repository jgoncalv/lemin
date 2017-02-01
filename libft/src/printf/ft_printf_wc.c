/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 20:19:44 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/12 13:53:45 by jgoncalv         ###   ########.fr       */
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

int			ft_printf_wc(wchar_t c, t_flag *flag)
{
	int		len;

	len = ft_wcharlen(c);
	if (flag->negative == 0)
	{
		if (flag->width_min > 0)
			len += ft_add_width(len, flag);
	}
	ft_putwchar(c);
	if (flag->negative == 1)
	{
		if (flag->width_min > 0)
			len += ft_add_width(len, flag);
	}
	return (len);
}
