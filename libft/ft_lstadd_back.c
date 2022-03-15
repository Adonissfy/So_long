/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:32:23 by asaffroy          #+#    #+#             */
/*   Updated: 2021/11/09 16:45:08 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*str;

	if (new == NULL)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		str = ft_lstlast(*alst);
		str->next = new;
	}
}
