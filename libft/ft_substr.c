/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:52:59 by jpreissn          #+#    #+#             */
/*   Updated: 2021/11/24 16:52:59 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len) // erstellt neuen String
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)						// wenn start outside string allocate memory für neuen leeren string der dann zurückgegeben wird
	{
		substr = malloc(sizeof(char));
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (start + len > ft_strlen(s))					// wenn substring über die Länge des strings laufen würde
		len = ft_strlen(s) - start;					// wird Länge gekürzt
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (++i - 1 < len)
		*(substr + i - 1) = *(s + start + i - 1);
	*(substr + i - 1) = '\0';
	return (substr);
}
