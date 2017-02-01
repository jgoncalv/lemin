/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:11:17 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/14 13:11:34 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_tflag_init(t_flag *flag)
{
	flag->sharp = 0;
	flag->zero = 0;
	flag->negative = 0;
	flag->positive = 0;
	flag->width_min = 0;
	flag->precision_ok = 0;
	flag->precision = 0;
	flag->length_modifier = none;
}

static	int		ft_printf_resolve(char **format, va_list arg)
{
	t_flag	flag;
	int		len;

	len = 0;
	ft_tflag_init(&flag);
	while (ft_strchr("#0123456789-.+ lhjz", **format) && **format)
	{
		ft_check_flag(format, &flag);
		ft_check_precision(format, &flag);
		ft_check_width(format, &flag);
		ft_check_modifier(format, &flag);
	}
	if (ft_isalpha(**format) || **format == '%')
	{
		len = ft_check_flag_base(arg, **format, &flag);
	}
	else if ((!(ft_strchr("sSdDoOxXpiuUcC", **format)) && **format != '%')
		|| !**format)
		return (0);
	(*format)++;
	return (len);
}

static	int		ft_read_format(char **format, va_list arg)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	while (**format)
	{
		if (!(str = ft_strchr(*format, '%')))
		{
			write(1, *format, ft_strlen(*format));
			len += ft_strlen(*format);
			break ;
		}
		write(1, *format, str - *format);
		len += str - *format;
		*format = str + 1;
		len += ft_printf_resolve(format, arg);
	}
	return (len);
}

int				ft_printf(const char *format, ...)
{
	int		len;
	char	*str;
	va_list	arg;

	va_start(arg, format);
	str = (char*)format;
	len = ft_read_format(&str, arg);
	va_end(arg);
	return (len);
}
