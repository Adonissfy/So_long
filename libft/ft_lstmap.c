/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:23:46 by asaffroy          #+#    #+#             */
/*   Updated: 2021/11/09 17:30:07 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*str;

	if (lst == NULL)
		return (NULL);
	new_lst = NULL;
	while (lst != NULL)
	{
		str = ft_lstnew((*f)(lst->content));
		if (str == NULL)
			ft_lstclear(&str, (*del));
		else
			ft_lstadd_back(&new_lst, str);
		lst = lst->next;
	}
	return (new_lst);
}
