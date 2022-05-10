/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:17:34 by jpreissn          #+#    #+#             */
/*   Updated: 2021/12/09 22:17:34 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*head;
	t_list	*temp;

	if (!del || !lst)
		return ;
	head = *lst;
	temp = NULL;
	while (head)
	{
		temp = head;
		head = head->next;
		del(temp->content);
		free(temp);
	}
	*lst = NULL;
}

// Deletes a given element and every element after that, 
// using the function ’del’ and free(3). 
// Finally, the pointer to the list must be set to NULL.