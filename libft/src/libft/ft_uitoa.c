/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:12:19 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/07 17:05:50 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_ilen(uintmax_t n)
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

char		*ft_uitoa(uintmax_t n)
{
	char	*str;
	int		len;
	int		i;

	len = ft_ilen(n);
	i = 0;
	if (n == 0)
		len++;
	if (!(str = ft_strnew(sizeof(char) * len)))
		return (NULL);
	str[len] = '\0';
	while (len)
	{
		str[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (str);
}
