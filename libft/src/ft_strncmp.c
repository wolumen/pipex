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

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (str1[i] == str2[i] && i < n && str1[i] != '\0')
		i++;
	if (i == n || !str1 || !str2)
		return (0);
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

// RETRUN:
// 0	Die verglichenen Strings sind bis zum angegebenen Zeichen identisch
// <0>	Die verglichenen Strings sind nicht identisch