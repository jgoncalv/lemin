/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:10:21 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/12 12:30:01 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newlst;

	if (!(newlst = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		newlst->content = NULL;
		newlst->content_size = 0;
	}
	else
	{
		if (!(newlst->content = (void*)malloc(sizeof(content))))
			return (NULL);
		ft_memcpy(newlst->content, content, content_size);
		newlst->content_size = content_size;
		newlst->next = NULL;
	}
	return (newlst);
}
