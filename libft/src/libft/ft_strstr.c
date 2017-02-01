/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:51:57 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/11/07 18:10:54 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int k;

	i = 0;
	if (!*little)
		return ((char*)big);
	while (big[i])
	{
		j = 0;
		k = i;
		while (big[k] == little[j])
		{
			j++;
			k++;
			if (little[j] == '\0')
				return ((char*)(&big[i]));
		}
		i++;
	}
	return (0);
}
