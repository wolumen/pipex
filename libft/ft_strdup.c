/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:21:16 by jpreissn          #+#    #+#             */
/*   Updated: 2021/11/24 14:21:16 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str1)
{
	char	*copy;
	int		i;

	copy = (char *)malloc(sizeof(*str1) * (ft_strlen(str1) + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (str1[i])
	{
		copy[i] = str1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
