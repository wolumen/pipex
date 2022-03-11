/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:13:36 by jpreissn          #+#    #+#             */
/*   Updated: 2021/11/23 17:13:36 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)			// "Fine0\0" = {70, 105, 110, 101, 48, 0}
{
	while (*str)
	{
		if (((unsigned char)*str) == c)				//casten weil int c Parameter, um mehr als Ascii suchen zu können. ZB ö
			return ((char *)str);
		str++;
	}												// hier sind wir bei "\0" angekommen
	if (c == 0)										// c = 0 ? Abfrage extra weil while (*str) nicht 0 sein kann
		return ((char *)str);
	return (NULL);
}

 // return is a pointer to the matched character or NULL if the character is not found.  
 // The terminating null byte is considered part of the string, so that if c is specified as '\0', 
 // these functions return a pointer to the terminator.
