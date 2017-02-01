/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:34:55 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/05 13:39:07 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_ilen(uintmax_t n, int base)
{
	int len;

	len = 0;
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char		*ft_uitoa_base(uintmax_t n, int base, int upper)
{
	char	*str;
	int		len;

	len = ft_ilen(n, base);
	if (n == 0)
		len = 1;
	if (!(str = ft_strnew(sizeof(char) * len)))
		return (NULL);
	str[len] = '\0';
	while (len)
	{
		if (upper == 0)
			str[len - 1] = (n % base) + (n % base > 9 ? 'a' - 10 : '0');
		else
			str[len - 1] = (n % base) + (n % base > 9 ? 'A' - 10 : '0');
		n /= base;
		len--;
	}
	return (str);
}
