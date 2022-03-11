/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:41:10 by jpreissn          #+#    #+#             */
/*   Updated: 2021/11/24 17:41:10 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			i;
	int			j;
	char		*s3;

	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);	
	i = 0;
	j = 0;
	while (s1 && s1[i])
		s3[j++] = s1[i++];				// schreibt den ersten string s1 in den neuen string s3
	i = 0;
	while (s2 && s2[i])
		s3[j++] = s2[i++];				// schreibt den zweiten string s2 in den neuen string s3	
	s3[j] = '\0';
	return (s3);
}

// Allocates (with malloc(3)) and returns a new string, 
// which is the result of the concatenation of ’s1’ and ’s2’.
