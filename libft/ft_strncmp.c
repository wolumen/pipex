/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:47:36 by jpreissn          #+#    #+#             */
/*   Updated: 2021/11/23 17:47:36 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)	// it compares only the first n bytes of s1 and s2.
{																// The comparison is done using unsigned characters
	size_t	i;													// i muss size_t sein weil i und n in Zeile 22 verglichen werden

	i = 0;
	while (str1[i] == str2[i] && i < n && str1[i] != '\0')		// hört brim ersten Unterschied auf
		i++;
	if (i == n || !str1 || !str2)								
		return (0);												// returns  0 (false) if s1 and s2 are equal;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);	// returns any other number (true) if s1 and s2 are NOT equal
}																

// RETRUN:
// 0	Die verglichenen Strings sind bis zum angegebenen Zeichen identisch
// <0>	Die verglichenen Strings sind nicht identisch