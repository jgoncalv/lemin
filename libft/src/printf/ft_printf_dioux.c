/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dioux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:50:06 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/14 10:26:46 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_dioux(va_list arg, char c, t_flag *flag)
{
	if (c == 'd' || c == 'i')
		return (ft_printf_itoa(ft_modifier_di(arg, flag), flag));
	else if (c == 'o')
		return (ft_printf_uitoa_base(ft_modifier_oux(arg, flag), 8, flag, c));
	else if (c == 'u')
		return (ft_printf_uitoa_base(ft_modifier_oux(arg, flag), 10, flag, c));
	else if (c == 'x' || c == 'X')
		return (ft_printf_uitoa_base(ft_modifier_oux(arg, flag), 16, flag, c));
	else
		return (0);
}
