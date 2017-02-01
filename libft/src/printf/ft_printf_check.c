/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:11:25 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/14 13:11:57 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flag(char **format, t_flag *flag)
{
	while (ft_strchr("#0- +", **format) && **format != '\0')
	{
		if (**format == '#')
			flag->sharp = 1;
		else if (**format == '0' && flag->negative == 0)
			flag->zero = 1;
		else if (**format == '-')
		{
			if (flag->zero == 1 || flag->space == 1)
				flag->zero = 0;
			flag->negative = 1;
		}
		else if (**format == '+')
		{
			if (flag->space == 1)
				flag->space = 0;
			flag->positive = 1;
		}
		else if (**format == ' ' && flag->positive == 0 && flag->negative == 0)
			flag->space = 1;
		(*format)++;
		while (**format == *(*format - 1))
			(*format)++;
	}
}

void	ft_check_width(char **format, t_flag *flag)
{
	if (ft_isdigit(**format) && **format != '\0')
	{
		while (ft_isdigit(**format))
		{
			flag->width_min = (flag->width_min * 10) + (**format - '0');
			(*format)++;
		}
	}
}

void	ft_check_precision(char **format, t_flag *flag)
{
	if (**format == '.' && **format != '\0')
	{
		flag->precision_ok = 1;
		(*format)++;
		if (!(ft_isdigit(**format)))
		{
			return ;
		}
		while (ft_isdigit(**format))
		{
			flag->precision = (flag->precision * 10) + (**format - '0');
			(*format)++;
		}
	}
}

void	ft_check_modifier(char **format, t_flag *flag)
{
	if (ft_strchr("hljz", **format) && **format != '\0')
	{
		if (flag->length_modifier == none)
		{
			if (**format == 'h' && *(*format + 1) == 'h')
			{
				flag->length_modifier = hh;
				(*format)++;
			}
			else if (**format == 'l' && *(*format + 1) == 'l')
			{
				flag->length_modifier = ll;
				(*format)++;
			}
			else if (**format == 'h')
				flag->length_modifier = h;
			else if (**format == 'l')
				flag->length_modifier = l;
			else if (**format == 'j')
				flag->length_modifier = j;
			else if (**format == 'z')
				flag->length_modifier = z;
		}
		(*format)++;
	}
}

int		ft_check_flag_base(va_list arg, char c, t_flag *flag)
{
	if (ft_strchr("diouxX", c))
		return (ft_printf_dioux(arg, c, flag));
	else if (c == 'S' || (flag->length_modifier == l && c == 's'))
		return (ft_printf_ws(va_arg(arg, wchar_t*), flag));
	else if (c == 'C' || (flag->length_modifier == l && c == 'c'))
		return (ft_printf_wc(va_arg(arg, wint_t), flag));
	else if (c == 's')
		return (ft_printf_s(va_arg(arg, char*), flag));
	else if (c == 'c')
		return (ft_printf_c(va_arg(arg, int), flag));
	else if (c == '%')
		return (ft_printf_percent(flag));
	else if (ft_strchr("DOU", c))
	{
		flag->length_modifier = l;
		return (ft_printf_dioux(arg, ft_tolower(c), flag));
	}
	else if (c == 'p')
		return (ft_printf_p(va_arg(arg, unsigned long), flag));
	else if (ft_isalpha(c))
		return (ft_printf_c(c, flag));
	else
		return (0);
}
