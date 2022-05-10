/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:02:25 by jpreissn          #+#    #+#             */
/*   Updated: 2021/12/09 22:02:25 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)

{
	t_list	*head;

	head = *lst;
	if (*lst)
	{
		while (head->next)
			head = head->next;
		head->next = new;
	}
	else
		*lst = new;
}

// Adds the element ’new’ at the end of the linked list