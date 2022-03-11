/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:34:39 by jpreissn          #+#    #+#             */
/*   Updated: 2021/11/23 17:34:39 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)		// reverse - returns a pointer to the last occurrence of c in str
{
	int	i;

	i = ft_strlen((char *)str);
	while (i != -1)
	{
		if ((unsigned char)*(str + i) == c)		// es geht auch str[i], das ist aber ein Listenaufruf und keine pointeraritmethik
			return ((char *)(str + i));			// returns a pointer to the last occurrence of c in str
		i--;
	}
	return (NULL);
}


// str + i  -> Adresse
// *(str +1)-> Wert von Adresse
// (unsigned char)*(str +1) -> umcasten des Wertes worauf der Pointer zeigt
// (char *)(str + i) -> gibt die Adresse zurück unt castet die Art des Pointers auf die Adresse