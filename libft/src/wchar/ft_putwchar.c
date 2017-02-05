/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:12:43 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/08 14:41:31 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(wchar_t wc)
{
	if (wc <= 0x7F)
		ft_putchar(wc);
	else if (wc <= 0x7FF)
	{
		ft_putchar(((wc >> 6) & 0x1F) | 0xC0);
		ft_putchar((wc & 0x3F) | 0x80);
	}
	else if (wc <= 0xFFFF)
	{
		ft_putchar(((wc >> 12) & 0xF) | 0xE0);
		ft_putchar(((wc >> 6) & 0x3F) | 0x80);
		ft_putchar((wc & 0x3F) | 0x80);
	}
	else if (wc <= 0x1FFFFF)
	{
		ft_putchar(((wc >> 18) & 0x7) | 0xF0);
		ft_putchar(((wc >> 12) & 0x3F) | 0x80);
		ft_putchar(((wc >> 6) & 0x3F) | 0x80);
		ft_putchar((wc & 0x3F) | 0x80);
	}
}
