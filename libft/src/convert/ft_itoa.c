/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:35:27 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/04 16:39:22 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_len(intmax_t n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(intmax_t n)
{
	int		len;
	int		sign;
	char	*str;

	sign = 1;
	len = 0;
	if (n == 0 || n < 0)
	{
		if (n < 0)
			sign = -1;
		len++;
	}
	len = len + ft_len(n);
	if (!(str = (char*)malloc(len + 1)))
		return (NULL);
	str[len] = '\0';
	while (len)
	{
		str[len - 1] = sign * (n % 10) + '0';
		n = n / 10;
		len--;
	}
	if (sign == -1)
		str[len] = '-';
	return (str);
}
