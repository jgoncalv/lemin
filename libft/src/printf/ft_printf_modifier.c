/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_modifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:11:36 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/12 12:21:09 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_modifier_di(va_list arg, t_flag *flag)
{
	intmax_t ret;

	ret = va_arg(arg, intmax_t);
	if (flag->length_modifier != none)
	{
		if (flag->length_modifier == hh)
			ret = (char)ret;
		else if (flag->length_modifier == h)
			ret = (short)ret;
		else if (flag->length_modifier == ll)
			ret = (long)ret;
		else if (flag->length_modifier == l)
			ret = (long long)ret;
		else if (flag->length_modifier == j)
			ret = (intmax_t)ret;
		else if (flag->length_modifier == z)
			ret = (ssize_t)ret;
	}
	else
		ret = (int)ret;
	return (ret);
}

uintmax_t	ft_modifier_oux(va_list arg, t_flag *flag)
{
	uintmax_t	ret;

	ret = va_arg(arg, uintmax_t);
	if (flag->length_modifier != none)
	{
		if (flag->length_modifier == hh)
			ret = (unsigned char)ret;
		else if (flag->length_modifier == h)
			ret = (unsigned short)ret;
		else if (flag->length_modifier == ll)
			ret = (unsigned long)ret;
		else if (flag->length_modifier == l)
			ret = (unsigned long long)ret;
		else if (flag->length_modifier == j)
			ret = (uintmax_t)ret;
		else if (flag->length_modifier == z)
			ret = (size_t)ret;
	}
	else
		ret = (unsigned int)ret;
	return (ret);
}
