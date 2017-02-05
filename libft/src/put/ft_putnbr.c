/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:27:55 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/02 16:58:28 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(intmax_t n)
{
	if (n >= 10 || n <= -10)
	{
		ft_putnbr(n / 10);
		if (n < 0)
			ft_putchar((n % 10) * -1 + '0');
		else
			ft_putchar(n % 10 + '0');
	}
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			ft_putchar((n % 10) * -1 + '0');
		}
		else
			ft_putchar(n % 10 + '0');
	}
}
