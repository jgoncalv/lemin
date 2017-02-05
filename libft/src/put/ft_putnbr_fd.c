/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:38:29 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/11/13 13:58:57 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 10 || n <= -10)
	{
		ft_putnbr_fd(n / 10, fd);
		if (n < 0)
			ft_putchar_fd((n % 10) * -1 + '0', fd);
		else
			ft_putchar_fd(n % 10 + '0', fd);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			ft_putchar_fd((n % 10) * -1 + '0', fd);
		}
		else
			ft_putchar_fd(n % 10 + '0', fd);
	}
}
