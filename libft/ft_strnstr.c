/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:01:32 by jpreissn          #+#    #+#             */
/*   Updated: 2021/11/24 10:01:32 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)		// locates the	first occurrence of the	null-termi-nated 
     																		// string needle in the string haystack, 
																			// where not more than n characters are searched.
																			// Chars after `\0' are not searched.
{
	if (*needle == '\0')													// das gleiche wie !*needle. Und !needle -> needle == NULL
		return ((char *)haystack);
	while (*haystack)
	{
		if (n < ft_strlen(needle))
			break ;
		if (ft_strlen(haystack) < ft_strlen(needle))
			break ;
		if (ft_memcmp(haystack, needle, ft_strlen(needle)) == 0)
			return ((char *)haystack);
		n--;
		haystack++;
	}
	return (NULL);
}

// If little is an empty string, big is returned; if little occurs nowhere in big, NULL is returned; 
// otherwise a pointer to the first	character of the first occurrence of little is returned.