/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:07:57 by jpreissn          #+#    #+#             */
/*   Updated: 2021/11/22 17:07:57 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*d;
	char			*s;
	unsigned int	i;

	i = 0;
	d = (char *) dest;
	s = (char *) src;
	if (dest == src || !n)
		return (dest);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char 		str2[] = "Start stop";
// 	printf("Before ft_memcpy %s\n", str2);
// 	ft_memcpy(str2, str2 + 6, 4 * sizeof(char));
// 	printf("After ft_memcpy %s\n", str2);
// }
