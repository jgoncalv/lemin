/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:13:30 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/14 15:24:13 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnwstr(wchar_t *wstr, int n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j + ft_wcharlen(wstr[i]) <= n)
	{
		ft_putwchar(wstr[i]);
		j += ft_wcharlen(wstr[i]);
		i++;
	}
}
