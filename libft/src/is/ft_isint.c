/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 17:59:32 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/05 17:59:33 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(char *str)
{
	int			i;
	long long	nb;
	int			sign;

	i = 0;
	nb = 0;
	while (*str && *str == ' ')
		str++;
	sign = (*str == '-' ? -1 : 1);
	if (*str == '-' || *str == '+')
		str++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	while (*str)
	{
		if ((sign * (nb = nb * 10 + (*str - '0'))) > INT_MAX
			|| (sign * nb) < INT_MIN)
			return (0);
		str++;
	}
	return (1);
}
