/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:34:18 by jpreissn          #+#    #+#             */
/*   Updated: 2021/12/09 22:34:18 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*new;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));						// kompiert ein Element der Liste und wendet währenddessen die Funktionen an 
	if (!new)												// wenn Fehler auftritt retrun NULL
		return (NULL);
	start = new;											// structzeiger auf den Anfang der neuen Liste
	while (lst)
	{
		if (lst->next)
		{
			new->next = ft_lstnew(f(lst->next->content));	// kompiert ein Element ans Ende der neuen Liste und wendet währenddessen die Funktionen an 
			if (!(new->next))								// wie in Zeile23
			{
				ft_lstclear(&new, del);						// lösche gegenwärtiges Element
				return (NULL);
			}
			new = new->next;
		}
		lst = lst->next;
	}
	new->next = NULL;
	return (start);
}

//TODO new Iterates the list ’lst’ and applies the function
// ’f’ to the content of each element. Creates a new
// list resulting of the successive applications of
// the function ’f’. The ’del’ function is used to
// delete the content of an element if needed.
/* Applies function to a copy of the list, freeing when necessary */